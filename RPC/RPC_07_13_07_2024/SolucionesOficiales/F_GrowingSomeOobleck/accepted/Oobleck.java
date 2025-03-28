import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Oobleck {

	public static final int MAXC = 100;

	public static Circle[] circles = new Circle[2*MAXC];

	public static void main(String[] args) {

		PriorityQueue<PElement> q = new PriorityQueue<>();
		Scanner in = new Scanner(System.in);
		int n;
		n = in.nextInt();
		for(int i=0; i<n; i++) {
			double x, y, r, s;
			x = in.nextDouble();
			y = in.nextDouble();
			r = in.nextDouble();
			s = in.nextDouble();
			circles[i] = new Circle(x, y, r, s, 0.0);
			for(int j=0; j<i; j++) {
				double t = circles[i].timeToIntersect(circles[j], 0.0);
				q.add(new PElement(t, i, j));
			}
		}

		double t = 0.0;
		double prevt = 0.0;
		while (!q.isEmpty()) {
			PElement p = q.poll();
			Circle c1 = circles[p.i1];
			Circle c2 = circles[p.i2];
			if (!c1.active || !c2.active)
				continue;
//System.out.println((p.t-prevt) + " " + p.t + " " + p.i1 + c1 + " " + p.i2 + c2);
			c1.active = false;
			c2.active = false;
			t = p.t;
			if (t-prevt <= 0.0001) {
				//System.out.println("ERROR: two intersections within 0.0001: " + t + "," + prevt);
//				System.exit(-1);
			}
			prevt = t;
			double x = (c1.xc + c2.xc)/2.0;
			double y = (c1.yc + c2.yc)/2.0;
			double r1 = c1.getRadius(t);
			double r2 = c2.getRadius(t);
			double r = Math.sqrt(r1*r1 + r2*r2);
			double rate = c1.rate > c2.rate ? c1.rate : c2.rate;
			Circle newCircle = new Circle(x, y, r, rate, t);
			ArrayList<Integer> list = new ArrayList<>();	// check for continued ooblection
			do {
				list.clear();
				for(int i=0; i<n; i++) {
					if (circles[i].active && newCircle.overlap(circles[i], t))
						list.add(i);
				}
				if (list.size() > 0) {
					double area = newCircle.r*newCircle.r;
					double xsum = newCircle.xc;
					double ysum = newCircle.yc;
					for(int i : list) {
						double newr = circles[i].getRadius(t);
						area += newr*newr;
						xsum += circles[i].xc;
						ysum += circles[i].yc;
						if (circles[i].rate > rate)
							rate = circles[i].rate;
						circles[i].active = false;
					}
					newCircle.r = Math.sqrt(area);
					newCircle.xc = xsum/(list.size()+1);
					newCircle.yc = ysum/(list.size()+1);
					newCircle.rate = rate;
//System.out.println("  Merge with " + (list.size()+1) + " circles, resulting in radius, location = " + newCircle.r + " " + newCircle.xc + "," + newCircle.yc);
				}
			} while (list.size() > 0);
			circles[n++] = newCircle;
//System.out.println("  Adding new circle " + (n-1));
			for(int j=0; j<n-1; j++) {
				if (circles[j].active) { 
					double tt = circles[n-1].timeToIntersect(circles[j], t);
					q.add(new PElement(tt, n-1, j));
				}
			}
		}
		System.out.printf("%.8f %.8f\n%.8f\n", circles[n-1].xc, circles[n-1].yc, circles[n-1].getRadius(t));

	}


}

class Circle
{
	public double r;
	public double xc, yc;
	public double rate;
	public double createTime;
	public boolean active;

	public Circle(double xc, double yc, double r, double rate, double t)
	{
		this.xc = xc;
		this.yc = yc;
		this.r = r;
		this.rate = rate;
		createTime = t;
		active = true;
	}

	public double timeToIntersect(Circle c, double t)
	{
		double dx = xc - c.xc;
		double dy = yc - c.yc;
		double dist = Math.sqrt(dx*dx+dy*dy) - getRadius(t) - c.getRadius(t);
		return t + dist/(rate+c.rate);
	}

	public double getRadius(double t)
	{
		return r + rate*(t-createTime);
	}

	public boolean overlap(Circle c, double t)
	{
		double dx = xc - c.xc;
		double dy = yc - c.yc;
		double dist = Math.sqrt(dx*dx+dy*dy) - getRadius(t) - c.getRadius(t);
		return (dist <= 0.0);
	}
	
	public String toString()
	{
		return "(" + xc + "," + yc + " " + r + ")";
	}
}

class PElement implements Comparable<PElement>
{
	public double t;
	public int i1, i2;

	public PElement(double t, int i1, int i2)
	{
		this.t = t;
		this.i1 = i1;
		this.i2 = i2;
	}

	public int compareTo(PElement pe)
	{
		return t > pe.t ? 1 : -1;
	}
}

