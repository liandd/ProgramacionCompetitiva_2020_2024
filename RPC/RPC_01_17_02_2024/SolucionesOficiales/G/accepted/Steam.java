import java.util.ArrayList;
import java.util.Scanner;

public class Steam {

	public static final int MAXSEG = 100;
	public static final double TOL = 1e-8;
	
	public static Point tanp1, tanp2;			// two tangent point of circle along line of motion
	public static double cloudAngle;

	public static void main(String[] args) {

		double r, scx, scy, cloudDx, cloudDy, v;
		int n;
		Point [] points;
		Point cam;
		Scanner in = new Scanner(System.in);
		ArrayList<Segment> horizon = new ArrayList<>();

		n = in.nextInt();
		points = new Point[n+1];
		double x,y;
		for(int i=0; i<=n; i++) {
			x = in.nextInt();
			y = in.nextInt();
			points[i] = new Point(x,y);
		}
		x = in.nextInt();	
		y = findy(x, points);
		cam = new Point(x,y);				// fix this
		scx = in.nextInt();
		scy = in.nextInt();
		r = in.nextInt();
		cloudDx = in.nextInt();
		cloudDy = in.nextInt();
		v = in.nextDouble();
		cloudAngle = Math.atan2(cloudDy, cloudDx);
		tanp1 = new Point(scx + r*Math.cos(cloudAngle+Math.PI/2), scy+r*Math.sin(cloudAngle+Math.PI/2));
		tanp2 = new Point(scx + r*Math.cos(cloudAngle-Math.PI/2), scy+r*Math.sin(cloudAngle-Math.PI/2));
		int i = 0;
		while (i<=n && points[i].x < cam.x)
			i++;
		i--;
		Point prev;
		if (i >= 0) {
			//			System.out.println("add " + points[i] + "-" + points[i+1]);
			horizon.add(new Segment(points[i], points[i+1]));
			prev = points[i];
		}
		else {
			prev = points[0];
		}
		for(int j=i-1; j>=0; j--) {
			Segment s = new Segment(points[j], cam);
			if (s.isBelow(prev)) {
				if (prev.equals(points[j+1])) {
					horizon.add(0, new Segment(points[j], points[j+1]));
				}
				else {
					s = new Segment(cam, prev);
					Point isect = s.lineLineIntersection(new Segment(points[j], points[j+1]));
					horizon.add(0, new Segment(isect, prev));
					horizon.add(0, new Segment(points[j], isect));
				}
				prev = points[j];
			}
		}
		if (!prev.equals(points[0])) {
			double y0 = prev.y + (prev.y-cam.y)/(cam.x-prev.x)*(prev.x - points[0].x);
			Point isect = new Point(points[0].x, y0);
			horizon.add(0, new Segment(isect, prev));
		}
		//		if (!cam.equals(points[i+1])) {
		//			horizon.add(new Segment(points[i], points[i+1]));
		//		}
		prev = points[i+1];
		for(int j=i+2; j<=n; j++) {
			Segment s = new Segment(points[j], cam);
			//			System.out.println(s);
			if (s.isBelow(prev)) {
				if (prev.equals(points[j-1])) {
					horizon.add(new Segment(points[j-1], points[j]));
				}
				else {
					s = new Segment(cam, prev);
					Point isect = s.lineLineIntersection(new Segment(points[j-1], points[j]));
					horizon.add(new Segment(prev, isect));
					horizon.add(new Segment(isect, points[j]));
				}
				prev = points[j];
			}
		}
		if (!prev.equals(points[n])) {
			double yn = prev.y + (prev.y-cam.y)/(cam.x-prev.x)*(prev.x - points[n].x);
			Point isect = new Point(points[n].x, yn);
			horizon.add(new Segment(prev, isect));
		}
		for(i=0; i<horizon.size(); i++) {
			Segment s = horizon.get(i); 
			if (i == 0) {
				s.setPrev(new Point(s.p1.x-1, s.p1.y));
			}
			else {
				s.setPrev(horizon.get(i-1).p1);
			}
			if (i == horizon.size()-1) {
				s.setSucc(new Point(s.p2.x+1, s.p2.y));
			}
			else
				s.setSucc(horizon.get(i+1).p2);
		}
//for(Segment s : horizon) {
//	System.out.println(s);
//}
		// determine location of earliest appearance
		Point loc = null;
		double minDist = Double.MAX_VALUE;
		for(Segment s : horizon) {
			double angle = Math.atan2(s.p2.y-s.p1.y, s.p2.x-s.p1.x);
			PointDist sect = findIntersection(s, scx, scy, r, angle, cloudDx, cloudDy);
			if (sect != null) {
				if (sect.dist < minDist) {
					minDist = sect.dist;
					loc = sect.p;
				}
			}
		}
		if (minDist == Double.MAX_VALUE)
			System.out.println(-1);
		else {
			double time = minDist/v;
//			double angle = Math.atan2(loc.y-cam.y, loc.x - cam.x)*180.0/Math.PI;
//			System.out.printf("%.6f %.6f\n", angle, time);
			System.out.printf("%.7f\n", time);
		}
	}

	public static double findy(double x, Point[] points)
	{
		int i=0;
		while (i < points.length && points[i].x < x)
			i++;
		if (i == 0)
			return points[0].y;
		else
			return points[i-1].y + (points[i].y - points[i-1].y)/(points[i].x - points[i-1].x)*(x - points[i-1].x);
	}

	public static PointDist findIntersection(Segment s, double scx, double scy, double r, double angle, double sunDx, double sunDy)
	{
		double mindist = Double.MAX_VALUE;
		Point p = null;
		double sx = scx + r*Math.cos(angle+Math.PI/2);			// check for tangent intersections
		double sy = scy + r*Math.sin(angle+Math.PI/2);
		Point p1 = new Point(sx, sy);
		Point p2 = new Point(sx+sunDx, sy+sunDy);
		Point isect = s.segLineIntersection(p1, p2);
		if (isect != null) {
			mindist = p1.dist(isect);
			p = isect;
		}
		sx = scx + r*Math.cos(angle-Math.PI/2);
		sy = scy + r*Math.sin(angle-Math.PI/2);
		p1 = new Point(sx, sy);
		p2 = new Point(sx+sunDx, sy+sunDy);
		isect = s.segLineIntersection(p1, p2);
		if (isect != null) {
			double dist = p1.dist(isect);
			if (dist < mindist) {
				mindist = dist;
				p = isect;
			}
		}
//		if (p != null)
//			return new PointDist(p, mindist); 
		//System.out.println("  part 2");
		// check if endpoints of segment intersect
		//   moving circle by having circle stay still
		//   and moving endpoint in opposite direction
		sunDx *= -1;
		sunDy *= -1;
		double a = sunDx*sunDx + sunDy*sunDy;
		double vx = s.p1.x - scx;
		double vy = s.p1.y - scy;
		double b = 2*(vx*sunDx + vy*sunDy);
		double c = vx*vx + vy*vy - r*r;
		double desc = b*b - 4*a*c;
		if (desc >= 0) {
			double t1 = (-b + Math.sqrt(desc))/(2*a);
			double t2 = (-b - Math.sqrt(desc))/(2*a);
			if (t2 >= 0 && t2 < t1)
				t1 = t2;
			if (t1 >= 0) {
				isect = new Point(s.p1.x + t1*sunDx, s.p1.y + t1*sunDy);
				double dist = s.p1.dist(isect);
				if (passesEndPointCheck(isect, s, 1) && dist < mindist) {
					mindist = dist;
					p = s.p1;
				}
			}
		}
		vx = s.p2.x - scx;
		vy = s.p2.y - scy;
		b = 2*(vx*sunDx + vy*sunDy);
		c = vx*vx + vy*vy - r*r;
		desc = b*b - 4*a*c;
		if (desc >= 0) {
			double t1 = (-b + Math.sqrt(desc))/(2*a);
			double t2 = (-b - Math.sqrt(desc))/(2*a);
			if (t2 >= 0 && t2 < t1)
				t1 = t2;
			if (t1 >= 0) {
				isect = new Point(s.p2.x + t1*sunDx, s.p2.y + t1*sunDy);
				double dist = s.p2.dist(isect);
				if (passesEndPointCheck(isect, s, 2) && dist < mindist) {
					mindist = dist;
					p = s.p2;
				}
			}
		}
		if (p == null)
			return null;
		else
			return new PointDist(p, mindist);
	}
	
	public static boolean passesEndPointCheck(Point p, Segment s, int whichEndPoint)
	{
		if (!p.equals(tanp1) && !p.equals(tanp2))
			return true;
		if (whichEndPoint == 1) {
			double angle1 = Math.atan2(s.p2.y-s.p1.y, s.p2.x-s.p1.x);
			double angle2 = Math.atan2(s.p1.y-s.pPrev.y, s.p1.x-s.pPrev.x);
			return (Math.min(angle1, angle2) < cloudAngle && cloudAngle < Math.max(angle2, angle1));
		}
		else  {
			double angle1 = Math.atan2(s.pSucc.y-s.p2.y, s.pSucc.x-s.p2.x);
			double angle2 = Math.atan2(s.p1.y-s.p2.y, s.p1.x-s.p2.x);
			return (Math.min(angle1, angle2) < cloudAngle && cloudAngle < Math.max(angle2, angle1));
		}
	}
	
	public static boolean isZero(double d)
	{
		return (Math.abs(d) < TOL);
	}
}

class Point
{
	public static final double TOL = Steam.TOL;

	public double x, y;

	public Point(double x, double y)
	{
		this.x = x;
		this.y = y;
	}

	public double dist(Point p)
	{
		double dx = x-p.x;
		double dy = y-p.y;
		return Math.sqrt(dx*dx + dy*dy);
	}
	public String toString()
	{
		return "("+x+","+y+")";
	}

	public boolean equals(Point p)
	{
		return (Math.abs(x-p.x) < TOL && Math.abs(y-p.y) < TOL);
	}
}

class PointDist
{
	Point p;
	double dist;

	public PointDist(Point p, double dist)
	{
		this.p = p;
		this.dist = dist;
	}
}

class Segment
{
	public Point p1, p2;
	public Point pPrev, pSucc;

	public Segment(Point p1, Point p2)
	{
		if (p1.x < p2.x) {
			this.p1 = p1;
			this.p2 = p2;
		}
		else if (p1.x > p2.x) {
			this.p1 = p2;
			this.p2 = p1;
		}
		else if (p1.y < p2.y) {
			this.p1 = p1;
			this.p2 = p2;
		}
		else {
			this.p1 = p2;
			this.p2 = p1;
		}
	}
	
	public void setPrev(Point pPrev)
	{
		this.pPrev = pPrev;
	}

	public void setSucc(Point pSucc)
	{
		this.pSucc = pSucc;
	}

	public boolean isBelow(Point p)
	{
		double x1 = p2.x-p1.x;
		double y1 = p2.y-p1.y;
		double x2 = p.x-p1.x;
		double y2 = p.y-p1.y;
		return (x1*y2-x2*y1 <= 0.0);
	}

	public Point lineLineIntersection(Segment seg)
	{
		// given segments p+tr and q+us (p,1 points, r, s, vectors) then intersection of their lines occurs when
		//
		//     t = (q-p) cross s/(r cross s)
		//     u = (q-p) cross r/(r cross s)
		//
		//  if denon and numerator are 0, segments on same line  (this should not happen in this problem)
		//  if denom is 0, parallel and non colinear             (ditto)
		//  otherwise, intersection of segments if 0<=t,u<=1
		//

		double rx = p2.x-p1.x;
		double ry = p2.y-p1.y;
		double sx = seg.p2.x-seg.p1.x;
		double sy = seg.p2.y-seg.p1.y;
		double denom = sy * rx - sx * ry;
		if (denom == 0.0) {         // Lines are parallel.
			System.out.println("Parallel lines:  shouldn't happen");
			System.exit(-1);
		}
		double t = (sx * (p1.y - seg.p1.y) - sy * (p1.x - seg.p1.x))/denom;
		double u = (rx * (p1.y - seg.p1.y) - ry * (p1.x - seg.p1.x))/denom;
		return new Point ((p1.x + t*rx), (p1.y + t*ry));
	}

	public Point segLineIntersection(Point q1, Point q2)
	{
		// given segments p+tr and q+us (p,1 points, r, s, vectors) then intersection of their lines occurs when
		//
		//     t = (q-p) cross s/(r cross s)
		//     u = (q-p) cross r/(r cross s)
		//
		//  if denon and numerator are 0, segments on same line  (this should not happen in this problem)
		//  if denom is 0, parallel and non colinear             (ditto)
		//  otherwise, intersection of segment and line if 0<=t<=1 and u>=0
		//

		double rx = p2.x-p1.x;
		double ry = p2.y-p1.y;
		double sx = q2.x-q1.x;
		double sy = q2.y-q1.y;
		double denom = sy * rx - sx * ry;
		if (denom == 0.0) {         // Lines are parallel.
			return null;
			//			System.out.println("Parallel lines:  shouldn't happen");
			//			System.exit(-1);
		}
		double t = (sx * (p1.y - q1.y) - sy * (p1.x - q1.x))/denom;
		double u = (rx * (p1.y - q1.y) - ry * (p1.x - q1.x))/denom;
		//System.out.println("t,u value = " + t + " " + u);
		if (0 <= t && t <= 1 && u >= 0)
			return new Point ((p1.x + t*rx), (p1.y + t*ry));
		else
			return null;
	}

	public String toString()
	{
		return "[" + p1 + "-" + p2 + "]";
	}
}