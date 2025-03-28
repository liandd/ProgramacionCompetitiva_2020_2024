#!/usr/bin/python3
from sys import stdin
from collections import namedtuple
import math


"""
First, find a sequence of line segments that define the edge of what 
can be seen on either side of the camera.
Next, find whether the cloud of steam will cross any of these segments.
Get all the intersection points of the cloud of steam with the segments
and see which one is crossed first.

author: Finn Lidbetter
"""

Point = namedtuple('Point', ['x', 'y'])
Circle = namedtuple('Circle', ['p', 'r'])


def distance(p1, p2):
    dx = p2.x - p1.x
    dy = p2.y - p1.y
    return math.sqrt(dx*dx + dy*dy)


def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


def sign(value):
    if value > 0:
        return 1
    if value == 0:
        return 0
    if value < 0:
        return -1
    raise ValueError(f"Could not determine sign of {value}")


class Frac:
    def __init__(self, num, denom):
        if isinstance(num, Frac) or isinstance(denom, Frac):
            result = num / denom
            self.num = result.num
            self.denom = result.denom
        else:
            assert isinstance(num, int)
            assert isinstance(denom, int)
            gcf = gcd(abs(num), abs(denom))
            if denom < 0:
                num *= -1
                denom *= -1
            self.num = num // gcf
            self.denom = denom // gcf

    def reciprocal(self):
        return Frac(self.denom, self.num)

    def __mul__(self, other):
        if isinstance(other, int):
            return self * Frac(other, 1)
        if isinstance(other, float):
            return float(self) * other
        return Frac(self.num * other.num, self.denom * other.denom)

    __rmul__ = __mul__

    def __truediv__(self, other):
        if isinstance(other, int):
            return self * Frac(1, other)
        if isinstance(other, float):
            return float(self) * other
        return self * other.reciprocal()

    __floordiv__ = __truediv__

    def __add__(self, other):
        if isinstance(other, int):
            return self + Frac(other, 1)
        if isinstance(other, float):
            return float(self) + other
        return Frac(self.num * other.denom + self.denom * other.num, self.denom * other.denom)

    __radd__ = __add__

    def __neg__(self):
        return Frac(-self.num, self.denom)

    def negation(self):
        return Frac(-self.num, self.denom)

    def __sub__(self, other):
        if isinstance(other, int):
            return self - Frac(other, 1)
        if isinstance(other, float):
            return float(self) - other
        return self + other.negation()

    def __rsub__(self, other):
        if isinstance(other, int):
            return Frac(other, 1) - self
        if isinstance(other, float):
            return other - float(self)
        return other - self

    def __eq__(self, other):
        if isinstance(other, int):
            return self == Frac(other, 1)
        if isinstance(other, float):
            raise ValueError("Error, comparing Frac to Float")
        return self.num * other.denom == self.denom * other.num

    def __lt__(self, other):
        if isinstance(other, int):
            return self < Frac(other, 1)
        if isinstance(other, float):
            raise ValueError("Error, comparing Frac to Float")
        return self.num * other.denom < other.num * self.denom

    def __gt__(self, other):
        if isinstance(other, int):
            return self > Frac(other, 1)
        if isinstance(other, float):
            raise ValueError("Error, comparing Frac to Float")
        return self.num * other.denom > other.num * self.denom

    def __le__(self, other):
        return self < other or self == other

    def __ge__(self, other):
        return self > other or self == other

    def __ne__(self, other):
        return not self == other

    def __abs__(self):
        if self.num < 0:
            return Frac(-self.num, self.denom)
        return self

    def __float__(self):
        return self.num / self.denom

    def __str__(self):
        return f"{self.num}/{self.denom}"

    def __repr__(self):
        return str(self)


class Vector:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __add__(self, v2):
        return Vector(self.x + v2.x, self.y + v2.y)

    __radd__ = __add__

    def __sub__(self, v2):
        return self + v2.scale(-1)

    def scale(self, c):
        return Vector(self.x * c, self.y * c)

    def dot(self, v2):
        return self.x * v2.x + self.y * v2.y

    def cross(self, v2):
        return self.x * v2.y - self.y * v2.x

    def perp(self):
        return Vector(-self.y, self.x)

    def norm(self):
        norm = math.sqrt(float(self.x * self.x + self.y * self.y))
        if abs(int(norm) - norm) < 0.0000000001:
            return int(norm)
        return norm

    def unit(self):
        norm = self.norm()
        if isinstance(norm, int):
            return self.scale(Frac(1, norm))
        return self.scale(1 / self.norm())


class Segment:
    def __init__(self, p1, p2):
        self.p1 = p1
        self.p2 = p2

    def has_point(self, p):
        v1 = Vector(self.p2.x - self.p1.x, self.p2.y - self.p1.y)
        v2 = Vector(p.x - self.p1.x, p.y - self.p1.y)
        if v1.cross(v2) != 0:
            return False
        return min(self.p1.x, self.p2.x) <= p.x <= max(self.p1.x, self.p2.x) and \
            min(self.p1.y, self.p2.y) <= p.y <= max(self.p1.y, self.p2.y)

    def is_trivial(self):
        return self.p1 == self.p2

    def __str__(self):
        return f"[{self.p1}, {self.p2}]"

    def __repr__(self):
        return str(self)


class Line:
    def __init__(self, p1, p2):
        self.p1 = p1
        self.p2 = p2

    def intersection(self, segment):
        """
        Get the point of intersection between a line and a line segment.

        Return the segment if the entire segment is on the line.
        Return None if there is no intersection.
        """
        line_vector = Vector(self.p2.x - self.p1.x, self.p2.y - self.p1.y)
        v1 = Vector(segment.p1.x - self.p1.x, segment.p1.y - self.p1.y)
        v2 = Vector(segment.p2.x - self.p1.x, segment.p2.y - self.p1.y)
        cross_1 = line_vector.cross(v1)
        cross_2 = line_vector.cross(v2)
        if cross_1 == 0 and cross_2 == 0:
            return segment
        if cross_1 == 0:
            return segment.p1
        if cross_2 == 0:
            return segment.p2
        if sign(cross_1) == sign(cross_2):
            return None
        x1 = self.p1.x
        y1 = self.p1.y
        x2 = self.p2.x
        y2 = self.p2.y
        x3 = segment.p1.x
        y3 = segment.p1.y
        x4 = segment.p2.x
        y4 = segment.p2.y
        vals = [x1, y1, x2, y2, x3, y3, x4, y4]
        # https://en.wikipedia.org/wiki/Line-line_intersection
        x_num = (x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4)
        y_num = (x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4)
        denom = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4)
        if any(isinstance(val, float) for val in vals):
            px = x_num / denom
            py = y_num / denom
        else:
            px = Frac(x_num, denom)
            py = Frac(y_num, denom)
        return Point(px, py)

    def _circle_intersection(self, circle):
        """Get the intersection point(s) between this line and a circle."""
        # https://mathworld.wolfram.com/Circle-LineIntersection.html
        # Normalise the points on the line to a circle centered at (0, 0).
        x1 = self.p1.x - circle.p.x
        y1 = self.p1.y - circle.p.y
        x2 = self.p2.x - circle.p.x
        y2 = self.p2.y - circle.p.y
        r = circle.r
        dx = x2 - x1
        dy = y2 - y1
        dr_sq = dx * dx + dy * dy
        det = x1 * y2 - x2 * y1
        discriminant = r * r * dr_sq - det * det
        if discriminant < 0:
            return []
        dy_sgn = -1 if dy < 0 else 1
        p1y = (float(-det * dx) + float(abs(dy)) * math.sqrt(float(discriminant))) / float(dr_sq)
        p1x = (float(det * dy) + float(dy_sgn * dx) * math.sqrt(float(discriminant))) / float(dr_sq)
        # Translate the point back to the actual circle position.
        p1y += circle.p.y
        p1x += circle.p.x
        if discriminant == 0:
            return [Point(p1x, p1y)]
        p2y = (float(-det * dx) - float(abs(dy)) * math.sqrt(float(discriminant))) / float(dr_sq)
        p2x = (float(det * dy) - float(dy_sgn * dx) * math.sqrt(float(discriminant))) / float(dr_sq)
        # Translate the point back to the actual circle position.
        p2y += circle.p.y
        p2x += circle.p.x
        return [Point(p1x, p1y), Point(p2x, p2y)]

    def segment_radius_intersections(self, segment, radius):
        """Get the intersection points of this line and a segment with a radius around it."""
        assert isinstance(segment, Segment)
        assert isinstance(segment.p1, Point)
        assert isinstance(segment.p2, Point)
        segment_vector = Vector(segment.p2.x - segment.p1.x, segment.p2.y - segment.p1.y)
        perp = segment_vector.perp().unit().scale(radius)
        p1_vector = Vector(segment.p1.x, segment.p1.y)
        p2_vector = Vector(segment.p2.x, segment.p2.y)
        positive_shifted_1 = p1_vector + perp
        positive_shifted_2 = p2_vector + perp
        negative_shifted_1 = p1_vector - perp
        negative_shifted_2 = p2_vector - perp
        segment_1 = Segment(
            Point(positive_shifted_1.x, positive_shifted_1.y),
            Point(positive_shifted_2.x, positive_shifted_2.y),
        )
        segment_2 = Segment(
            Point(negative_shifted_1.x, negative_shifted_1.y),
            Point(negative_shifted_2.x, negative_shifted_2.y),
        )
        intersections = []
        segment_intersection_1 = self.intersection(segment_1)
        segment_intersection_2 = self.intersection(segment_2)
        # Disallow tangential intersections.
        if segment_intersection_1 is not None and not isinstance(segment_intersection_1, Segment):
            # Make sure the point is between the segment endpoints.
            v1 = Vector(segment_1.p2.x - segment_1.p1.x, segment_1.p2.y - segment_1.p1.y)
            v2 = v1.scale(-1)
            v3 = Vector(segment_intersection_1.x - segment_1.p1.x, segment_intersection_1.y - segment_1.p1.y)
            v4 = Vector(segment_intersection_1.x - segment_1.p2.x, segment_intersection_1.y - segment_1.p2.y)
            if v1.dot(v3) >= 0 and v2.dot(v4) >= 0:
                intersections.append(segment_intersection_1)
        if segment_intersection_2 is not None and not isinstance(segment_intersection_2, Segment):
            # Make sure the point is between the segment endpoints.
            v1 = Vector(segment_2.p2.x - segment_2.p1.x, segment_2.p2.y - segment_2.p1.y)
            v2 = v1.scale(-1)
            v3 = Vector(segment_intersection_2.x - segment_2.p1.x, segment_intersection_2.y - segment_2.p1.y)
            v4 = Vector(segment_intersection_2.x - segment_2.p2.x, segment_intersection_2.y - segment_2.p2.y)
            if v1.dot(v3) >= 0 and v2.dot(v4) >= 0:
                intersections.append(segment_intersection_2)
        circle_1 = Circle(segment.p1, radius)
        circle_1_intersections = self._circle_intersection(circle_1)
        # Disallow tangential intersections.
        if len(circle_1_intersections) == 1:
            circle_1_intersections = []
        circle_2 = Circle(segment.p2, radius)
        circle_2_intersections = self._circle_intersection(circle_2)
        # Disallow tangential intersections.
        if len(circle_2_intersections) == 1:
            circle_2_intersections = []
        for intersection in circle_1_intersections + circle_2_intersections:
            v1 = Vector(intersection.x - segment.p1.x, intersection.y - segment.p1.y)
            v2 = Vector(intersection.x - segment.p2.x, intersection.y - segment.p2.y)
            if sign(perp.cross(v1)) == sign(perp.cross(v2)):
                intersections.append(intersection)
        return intersections

    def __str__(self):
        return f'[{self.p1}, {self.p2}]'

    def __repr__(self):
        return str(self)


def get_cam_point(segments, cam_x):
    for segment in segments:
        p1 = segment.p1
        p2 = segment.p2
        if p1.x <= cam_x <= p2.x:
            dy = p2.y - p1.y
            frac = Frac(cam_x - p1.x, p2.x - p1.x)
            cam_y = p1.y + frac * dy
            return Point(cam_x, cam_y)


def _get_cam_segment_index(cam_point, segments):
    """Get the smallest index such that the camera is on the segment with that index."""
    for segment_index, segment in enumerate(segments):
        if segment.has_point(cam_point):
            return segment_index
    raise ValueError("Camera not found on any segment")


def get_visible_segments(cam_point, segments):
    cam_segment_index = _get_cam_segment_index(cam_point, segments)
    right_start_index = cam_segment_index
    if cam_point == segments[cam_segment_index].p2:
        right_start_index += 1
    visible_segments = []
    if right_start_index < len(segments):
        visible_segments.append(Segment(cam_point, segments[right_start_index].p2))
        line = Line(cam_point, segments[right_start_index].p2)
    else:
        line = Line(cam_point, Point(cam_point.x + 1, cam_point.y))
    line_vector = Vector(line.p2.x - line.p1.x, line.p2.y - line.p1.y)
    for segment in segments[right_start_index + 1:]:
        intersection = line.intersection(segment)
        v = Vector(segment.p2.x - cam_point.x, segment.p2.y - cam_point.y)
        if intersection is not None and line_vector.cross(v) >= 0:
            line = Line(cam_point, segment.p2)
            line_vector = Vector(line.p2.x - line.p1.x, line.p2.y - line.p1.y)
            if isinstance(intersection, Segment):
                visible_segments.append(intersection)
            else:
                prev_to_intersection = Segment(visible_segments[-1].p2, intersection)
                intersection_to_p2 = Segment(intersection, segment.p2)
                if not prev_to_intersection.is_trivial():
                    visible_segments.append(prev_to_intersection)
                if not intersection_to_p2.is_trivial():
                    visible_segments.append(intersection_to_p2)
    bounding_segment = Segment(Point(segments[-1].p2.x, segments[-1].p2.y), Point(segments[-1].p2.x, 10000000000))
    if cam_point != segments[-1].p2:
        last_segment = Segment(visible_segments[-1].p2, line.intersection(bounding_segment))
        if not last_segment.is_trivial():
            visible_segments.append(last_segment)
    if cam_point != segments[0].p1:
        visible_segments.append(Segment(segments[cam_segment_index].p1, cam_point))
        line = Line(cam_point, segments[cam_segment_index].p1)
    else:
        line = Line(cam_point, Point(cam_point.x - 1, cam_point.y))
    line_vector = Vector(line.p2.x - line.p1.x, line.p2.y - line.p1.y)
    for segment_index in range(cam_segment_index-1, -1, -1):
        segment = segments[segment_index]
        intersection = line.intersection(segment)
        v = Vector(segment.p1.x - cam_point.x, segment.p1.y - cam_point.y)
        if intersection is not None and line_vector.cross(v) <= 0:
            line = Line(cam_point, segment.p1)
            line_vector = Vector(line.p2.x - line.p1.x, line.p2.y - line.p1.y)
            if isinstance(intersection, Segment):
                visible_segments.append(intersection)
            else:
                intersection_to_prev = Segment(intersection, visible_segments[-1].p1)
                p1_to_intersection = Segment(segment.p1, intersection)
                if not intersection_to_prev.is_trivial():
                    visible_segments.append(intersection_to_prev)
                if not p1_to_intersection.is_trivial():
                    visible_segments.append(p1_to_intersection)
    bounding_segment = Segment(Point(segments[0].p1.x, 10000000000), Point(segments[0].p1.x, segments[0].p1.y))
    if cam_point != segments[0].p1:
        first_segment = Segment(line.intersection(bounding_segment), visible_segments[-1].p1)
        if not first_segment.is_trivial():
            visible_segments.append(first_segment)
    return visible_segments


def main():
    line = stdin.readline().strip()
    tokens = line.split(' ')
    n = int(tokens[0])
    points = []
    segments = []
    for i in range(n + 1):
        x = int(tokens[2*i + 1])
        y = int(tokens[2*i + 2])
        points.append(Point(x, y))
        if i > 0:
            segments.append(Segment(points[i - 1], points[i]))
    line = stdin.readline().strip()
    tokens = line.split(' ')
    cam_x = int(tokens[0])
    cam_point = get_cam_point(segments, cam_x)
    cx = int(tokens[1])
    cy = int(tokens[2])
    r = int(tokens[3])
    dx = int(tokens[4])
    dy = int(tokens[5])
    v = float(tokens[6])
    origin = Point(cx, cy)
    trajectory = Line(origin, Point(cx + dx, cy + dy))
    visible_segments = get_visible_segments(cam_point, segments)
    best_time = float('inf')
    for segment in visible_segments:
        intersections = trajectory.segment_radius_intersections(segment, r)
        for intersection in intersections:
            if isinstance(intersection, Segment):
                raise ValueError("Unexpected Segment in intersections.")
            else:
                if intersection.x < segments[0].p1.x - r or intersection.x > segments[-1].p2.x + r:
                    continue
                intersection_distance = distance(origin, intersection)
                v1 = Vector(dx, dy)
                v2 = Vector(intersection.x - cx, intersection.y - cy)
                if v1.dot(v2) < 0:
                    continue
                else:
                    intersection_time = intersection_distance / v
                    if intersection_time < best_time:
                        best_time = intersection_time
    if best_time == float('inf'):
        print(-1)
    else:
        print(best_time)


if __name__ == '__main__':
    main()
