#!/usr/bin/python3
from sys import stdin

"""
Use a recurrence relation for constructing the nth iteration of the
Hilbert Curve. Make progress by "escaping" from the nested depths of the 
maze. Escape from the deepest level first. If the two points ever end up
at the same level within the same "sub-curve" and they exit to the same 
position, then we can evaluate the direct manhattan distance between them. 
Be very careful in deciding what the "deepest" level is.
O(k log^2 n)
:author Finn Lidbetter
"""

RECURRENCE = {
    'N': [
        ['N', 'N'],
        ['E', 'W'],
    ],
    'E': [
        ['S', 'E'],
        ['N', 'E'],
    ],
    'S': [
        ['E', 'W'],
        ['S', 'S'],
    ],
    'W': [
        ['W', 'S'],
        ['W', 'N'],
    ]
}


class SubCurve:
    def __init__(self, size, lower_x, lower_y, dir):
        self.size = size
        self.lower_x = lower_x
        self.lower_y = lower_y
        self.dir = dir

    def get_parent(self):
        """Get the 2^n by 2^n block containing the current block."""
        parent_size = self.size * 2
        x_side = 0 if self.lower_x % parent_size == 0 else 1
        y_side = 0 if self.lower_y % parent_size == 0 else 1
        parent_dir = 'N'
        for key, value in RECURRENCE.items():
            if value[1 - y_side][x_side] == self.dir:
                parent_dir = key
                break
        parent_lower_x = self.lower_x - (self.size * x_side)
        parent_lower_y = self.lower_y - (self.size * y_side)
        return SubCurve(parent_size, parent_lower_x, parent_lower_y, parent_dir)

    def get_exit_xy(self, x, y):
        """Get the coordinates of the first point in an adjacent sub-curve."""
        parent = self.get_parent()
        if parent.dir == 'N':
            if self.lower_y > parent.lower_y:
                return self.lower_x + self.size - 1, self.lower_y + self.size - 1
            if self.lower_x > parent.lower_x:
                return self.lower_x - 1, self.lower_y + self.size - 1
            return self.lower_x + self.size - 1, self.lower_y - 1
        elif parent.dir == 'E':
            if self.lower_x > parent.lower_x:
                return self.lower_x + self.size - 1, self.lower_y + self.size - 1
            if self.lower_y > parent.lower_y:
                return self.lower_x + self.size - 1, self.lower_y - 1
            return self.lower_x - 1, self.lower_y + self.size - 1
        elif parent.dir == 'S':
            if self.lower_x > parent.lower_x:
                return self.lower_x - 1, self.lower_y + self.size - 1
            if self.lower_y > parent.lower_y:
                return self.lower_x + self.size - 1, self.lower_y + self.size - 1
            # Need to check if we are above or to the right.
            if y == self.lower_y + self.size - 1:
                # Escape to between E and W.
                return self.lower_x + self.size - 1, self.lower_y + self.size
            else:
                # We are between S and S. Escape to the South.
                return self.lower_x + self.size - 1, self.lower_y - 1
        else:  # parent.dir == 'W'
            if self.lower_x > parent.lower_x:
                return self.lower_x + self.size - 1, self.lower_y + self.size - 1
            if self.lower_y > parent.lower_y:
                return self.lower_x + self.size - 1, self.lower_y - 1
            # Need to check if we are above or to the right.
            if x == self.lower_x + self.size - 1:
                # Escape to between S and N.
                return self.lower_x + self.size, self.lower_y + self.size - 1
            else:
                # We are between W and W. Escape to the West.
                return self.lower_x - 1, self.lower_y + self.size - 1

    def __key(self):
        return self.size, self.lower_x, self.lower_y, self.dir

    def __hash__(self):
        return hash(self.__key())

    def __eq__(self, other):
        if isinstance(other, SubCurve):
            return self.__key() == other.__key()
        if other is None:
            return False
        return NotImplemented

    def __str__(self):
        return f"SubCurve(size={self.size}, lower_x={self.lower_x}, lower_y={self.lower_y}, dir={self.dir})"


def get_sub_curve(curve_iterations, x, y):
    """
    Get the largest 2^n by 2^n block (and its orientation) for which either:
        x % 2^n = 2^n - 1, or
        y % 2^n = 2^n - 1.
    Return None if outside the hedge maze.
    """
    size = 2 ** curve_iterations
    lower_x = 0
    lower_y = 0
    dir = 'N'
    if x < 0 or y < 0 or x >= size - 1 or y >= size - 1:
        return None
    relative_x = x
    relative_y = y
    while relative_x != size - 1 and relative_y != size - 1 and size > 2:
        half_size = size // 2
        x_side = relative_x // half_size
        y_side = relative_y // half_size
        dir = RECURRENCE[dir][1 - y_side][x_side]
        lower_x += x_side * half_size
        lower_y += y_side * half_size
        relative_x = relative_x % half_size
        relative_y = relative_y % half_size
        size = half_size
    return SubCurve(size, lower_x, lower_y, dir)


def outside_distance(curve_iterations, x1, y1, x2, y2):
    """Get the distance between 2 positions outside the hedge maze."""
    size = 2 ** curve_iterations
    dx = abs(x2 - x1)
    dy = abs(y2 - y1)
    if 0 <= x1 <= size - 2 and 0 <= x2 <= size - 2 and min(y1, y2) < 0 and max(y1, y2) > size - 2:
        dx = min(x1 + 1 + x2 + 1, ((size - 1) - x1) + ((size - 1) - x2))
    if 0 <= y1 <= size - 2 and 0 <= y2 <= size - 2 and min(x1, x2) < 0 and max(x1, x2) > size - 2:
        dy = min(y1 + 1 + y2 + 1, ((size - 1) - y1) + ((size - 1) - y2))
    return dx + dy


def solve(curve_iterations, x1, y1, x2, y2):
    """Recursively get the distance between two positions."""
    if x1 == x2 and y1 == y2:
        return 0
    sub_curve_1 = get_sub_curve(curve_iterations, x1, y1)
    sub_curve_2 = get_sub_curve(curve_iterations, x2, y2)
    #print(f'{x1} {y1} {x2} {y2}')
    #print(f'\t{sub_curve_1}')
    #if sub_curve_1 is not None:
    #    print(f'\t\t{sub_curve_1.get_exit_xy(x1,y1)}')
    #print(f'\t{sub_curve_2}')
    #if sub_curve_2 is not None:
    #    print(f'\t\t{sub_curve_2.get_exit_xy(x2,y2)}')
    if sub_curve_1 is None and sub_curve_2 is None:
        # Both points are outside.
        return outside_distance(curve_iterations, x1, y1, x2, y2)
    if sub_curve_1 is None:
        # Switch point 1 and point 2 for convenience. We want to
        # work on escaping from the deeper level.
        return solve(curve_iterations, x2, y2, x1, y1)
    if sub_curve_2 is not None and sub_curve_2.size < sub_curve_1.size:
        # Switch point 1 and point 2 for convenience. We want to
        # work on escaping from the deeper level.
        return solve(curve_iterations, x2, y2, x1, y1)
    if x1 % 2 == 0 and y1 % 2 == 0:
        # We are not yet in a corridor. Take the only step we can.
        if sub_curve_1.dir == 'N':
            dx = 0
            dy = -1
        elif sub_curve_1.dir == 'E':
            dx = -1
            dy = 0
        elif sub_curve_1.dir == 'S':
            dx = 0
            dy = 1
        else:
            dx = 1
            dy = 0
        return 1 + solve(curve_iterations, x1 + dx, y1 + dy, x2, y2)
    if sub_curve_2 is not None and x2 % 2 == 0 and y2 % 2 == 0:
        # We are not yet in a corridor. Take the only step we can.
        if sub_curve_2.dir == 'N':
            dx = 0
            dy = -1
        elif sub_curve_2.dir == 'E':
            dx = -1
            dy = 0
        elif sub_curve_2.dir == 'S':
            dx = 0
            dy = 1
        else:
            dx = 1
            dy = 0
        return 1 + solve(curve_iterations, x1, y1, x2 + dx, y2 + dy)
    if sub_curve_1 == sub_curve_2 and sub_curve_1.get_exit_xy(x1, y1) == sub_curve_2.get_exit_xy(x2, y2):
        # If we are in the same sub-curve and they exit to the same position, then 
        # there is a direct path.
        return abs(x2 - x1) + abs(y2 - y1)
    if sub_curve_2 is None:
        # If point 2 is outside the hedge maze, then we need to escape from
        # point 1 until it reaches the outside too.
        exit_x, exit_y = sub_curve_1.get_exit_xy(x1, y1)
        exit_distance = abs(x1 - exit_x) + abs(y1 - exit_y)
        return exit_distance + solve(curve_iterations, exit_x, exit_y, x2, y2)
    exit_x_1, exit_y_1 = sub_curve_1.get_exit_xy(x1, y1)
    exit_distance_1 = abs(x1 - exit_x_1) + abs(y1 - exit_y_1)
    if sub_curve_1.size < sub_curve_2.size:
        # Escape from the deeper level first.
        return exit_distance_1 + solve(curve_iterations, exit_x_1, exit_y_1, x2, y2)
    # The sub-curves are at the same level.
    parent_1 = sub_curve_1.get_parent()
    parent_2 = sub_curve_2.get_parent()
    exit_x_2, exit_y_2 = sub_curve_2.get_exit_xy(x2, y2)
    exit_distance_2 = abs(x2 - exit_x_2) + abs(y2 - exit_y_2)
    if parent_1 != parent_2:
        # It does not matter which one we exit first. They will not meet up in the next
        # level.
        return exit_distance_2 + solve(curve_iterations, x1, y1, exit_x_2, exit_y_2)
    common_parent = parent_1
    # The sub-curves have the same parent! There may be a direct path!
    exit_sub_curve_1 = get_sub_curve(curve_iterations, exit_x_1, exit_y_1)
    exit_sub_curve_2 = get_sub_curve(curve_iterations, exit_x_2, exit_y_2)
    if exit_sub_curve_1 is None:
        # Sub-curve 1 exits to outside of the maze.
        # If sub-curve 2 also exits to outside the maze then we can choose to exit either,
        # since sub-curve 1 and sub-curve 2 are not equal.
        # If sub-curve 2 does not exit to outside the maze, then we should choose to exit
        # sub-curve 2 first in case it exits to sub-curve 1.
        return exit_distance_2 + solve(curve_iterations, x1, y1, exit_x_2, exit_y_2)
    if exit_sub_curve_2 is None:
        # Same argument as exit_sub_curve_1 is None (but in reverse) applies here.
        return exit_distance_1 + solve(curve_iterations, exit_x_1, exit_y_1, x2, y2)
    if exit_sub_curve_1 == sub_curve_2:
        # If exiting from x1,y1 takes us to the sub_curve of x2, y2, then the move is safe.
        return exit_distance_1 + solve(curve_iterations, exit_x_1, exit_y_1, x2, y2)
    if exit_sub_curve_2 == sub_curve_1:
        # If exiting from x2,y2 takes us to the sub_curve of x1, y1, then the move is safe.
        return exit_distance_2 + solve(curve_iterations, x1, y1, exit_x_2, exit_y_2)
    # x1,y1 and x2,y2 are not in adjacent sub-curves, but there could still be a direct path
    # between them. Check if exiting from one of them preserves the parent.
    if exit_sub_curve_1.get_parent() == common_parent:
        # If exiting sub-curve 1 preserves its parent, then the move is safe.
        return exit_distance_1 + solve(curve_iterations, exit_x_1, exit_y_1, x2, y2)
    if exit_sub_curve_2.get_parent() == common_parent:
        # If exiting sub-curve 2 preserves its parent, then the move is safe.
        return exit_distance_2 + solve(curve_iterations, x1, y1, exit_x_2, exit_y_2)
    # If exiting sub-curve 1 does not take us to sub-curve 2 and exiting sub-curve 2 does
    # not take us to sub-curve 1, and exiting does not preserve either's parent, then we 
    # can safely exit from either.
    return exit_distance_2 + solve(curve_iterations, x1, y1, exit_x_2, exit_y_2)


def main():
    line = stdin.readline()
    n_cases = int(line)
    for test_case in range(n_cases):
        line = stdin.readline()
        tokens = line.split(' ')
        curve_iterations = int(tokens[0])
        x1 = int(tokens[1])
        y1 = int(tokens[2])
        x2 = int(tokens[3])
        y2 = int(tokens[4])
        print(solve(curve_iterations, x1, y1, x2, y2))


if __name__ == '__main__':
    main()
