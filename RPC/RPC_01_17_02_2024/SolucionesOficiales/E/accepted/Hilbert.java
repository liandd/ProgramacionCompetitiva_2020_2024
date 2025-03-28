import java.util.ArrayList;
import java.util.Scanner;

public class Hilbert {

	public static void main(String[] args) {

		int k;
		long x1, y1, x2, y2, size, extraDist = 0;
		int level;
		ArrayList<Location> path1, path2;
		Scanner in = new Scanner(System.in);

		k = in.nextInt();
		for(int i=1; i<=k; i++) {
			level = in.nextInt();
			x1 = in.nextLong();
			y1 = in.nextLong();
			x2 = in.nextLong();
			y2 = in.nextLong();
			size = (long) Math.pow(2,  level);
			extraDist = 0;
			if (x1<=-1 && x2 <=-1 ||					// special cases
			    x1 >=size-1 && x2 >= size-1 ||
			    y1<=-1 && y2 <=-1 ||
			    y1 >=size-1 && y2 >= size-1) {
				System.out.println(Math.abs(x1-x2) + Math.abs(y1-y2));
				continue;
			}
			else if (x1 == x2 && y1 == y2) {
				System.out.println(0);
				continue;
			}
			if (x1 < -1) {						// move point 1 to edge of hedge if necessary
				extraDist += -1-x1;
				x1 = -1;
			}
			else if (x1 > size-1) {
				extraDist += x1 - (size-1);
				x1 = size-1;
			}
			if (y1 < -1) {	
				extraDist += -1-y1;
				y1 = -1;
			}
			else if (y1 > size-1) {
				extraDist += y1 - (size-1);
				y1 = size-1;
			}
			if (x2 < -1) {						// move point 2 to edge of hedge if necessary
				extraDist += -1-x2;
				x2 = -1;
			}
			else if (x2 > size-1) {
				extraDist += x2 - (size-1);
				x2 = size-1;
			}
			if (y2 < -1) {	
				extraDist += -1-y2;
				y2 = -1;
			}
			else if (y2 > size-1) {
				extraDist += y2 - (size-1);
				y2 = size-1;
			}
//System.out.println(x1 + " " + y1 + " " + x2 + " " + y2 + " " + extraDist);
			path1 = getPath(x1, y1, level);
			extendToExterior(path1);
//for(Location loc : path1) {
//System.out.println(loc.level + " (" + loc.x + "," + loc.y + ") " + loc.d);
//} 
			path2 = getPath(x2, y2, level);
			extendToExterior(path2);
//for(Location loc : path2) {
//System.out.println(loc.level + " (" + loc.x + "," + loc.y + ") " + loc.d);
//}
			if (!path1.get(0).equals(path2.get(0)))
				System.out.println(getExteriorDistance(path1.get(0), path2.get(0), (long)Math.pow(2,level)) + path1.get(0).d + path2.get(0).d + extraDist);
			else {
				int i1=0, i2=0;
				while (i1 < path1.size()-1 && i2 < path2.size()-1 && path1.get(i1).equals(path2.get(i2))) {
//					level = path1.get(i1).level;
//					if (path1.get(++i1).level == level)
						i1++;
//					level = path1.get(i2).level;
//					if (path2.get(++i2).level == level)
						i2++;
				}
				long dist = path1.get(i1).d + path2.get(i2).d
						+ Math.abs(path1.get(i1).x-path2.get(i2).x) + Math.abs(path1.get(i1).y-path2.get(i2).y);
				System.out.println(dist + extraDist);
			}
		};
	}

	public static ArrayList<Location> getPath(long x, long y, int level)
	{
		ArrayList<Location> ans;
//System.out.println("call: " + x + "," + y + "," + level);
		long d = 0;
		if (level == 1) {
			if (x == 0 && y == 0) {			// only distance need traveled for base case
				d = 1;
				y = -1;
			}
			ans = new ArrayList<>();
			ans.add(new Location(level,x,y,d));
			return ans;
		}
		// determine which quadrant (x,y) falls in    2 | 3
		//                                           ---+---
		//                                            0 | 1
		long size = (long)Math.pow(2,level);
		int quad = 0;
		if (x >= size/2)
			quad++;
		if (y >= size/2)
			quad += 2;
		// convert (x, y) to point relative to quadrant
		long newx, newy;
		switch (quad) {
		case 0: newx = size/2 - 2 - y;
		newy = x;
		break;
		case 1: newx = y;
		newy = size - 2 - x;
		break;
		case 2: newx = x;
		newy = y - size/2;
		break;
		default: newx = x - size/2;
		newy = y - size/2;
		}
		ans = getPath(newx, newy, level-1);
		Location l = ans.get(0);
//System.out.println("level = " + level + " (" + l.x + "," + l.y + ") " + l.d + " size = " + size);
		d = l.d;
		newx = l.x;
		newy = l.y;
		if (newx > -1 && newx < size/2-1 && newy > -1 && newy < size/2-1) {		// point in interior
			if (newy <= size/4-1) {
				d += Math.abs(size/4-1-newx);
				newx = size/4-1;
				ans.add(0, new Location(level,newx, newy, d));
				d += newy+1;
				newy = -1;
			}
			else {
				d += size/2 - 1 - newy;
//				newx = size/4;
				newy = size/2-1;
			}
		}
//System.out.println("  add (" + newx + "," + newy + ") " + d);
		ans.add(0, new Location(level,newx,newy,d));

		for(Location loc : ans) {		// convert to local coordinates
			switch (quad) {
			case 0: x = loc.y;
			y = size/2 - 2 - loc.x;
			break;
			case 1: x = size - 2 - loc.y;
			y = loc.x;
			break;
			case 2: x = loc.x;
			y = loc.y + size/2;
			break;
			default: x = loc.x + size/2;
			y = loc.y + size/2;
			}
//System.out.print("("+loc.x+","+loc.y+") --> (" + x + "," + y + ")");
			loc.x = x;
			loc.y = y;
		}
//System.out.println();
		return ans;
	}
	
	public static void extendToExterior(ArrayList<Location> path)
	{
		long newx = path.get(0).x;
		long newy = path.get(0).y;
		long d = path.get(0).d;
		int level = path.get(0).level;
		long size = (long)Math.pow(2,level);
		if (newx > -1 && newx < size-1 && newy > -1 && newy < size-1) {		// add point to get to exterior if necessary
			if (newy <= size/2-1) {
				d += Math.abs(size/2-1-newx);
				newx = size/2-1;
				path.add(0, new Location(level+1,newx, newy, d));
				d += newy+1;
				newy = -1;
			}
			else {
//System.out.println("here:" + size + " " + newx + " " + newx);
				d += size-1 - newy;
//				newx = size/2;
				newy = size-1;
			}
		}
		path.add(0, new Location(level+1,newx,newy,d));
	}

	public static long getExteriorDistance(Location loc1, Location loc2, long size)
	{
		int edge1 = getEdge(loc1, size);
		int edge2 = getEdge(loc2, size);
		switch (edge1) {
		case 0: switch(edge2) {
			case 0 : return Math.abs(loc1.x-loc2.x);
			case 1 : return loc1.x+1 + loc2.y+1;
			case 2 : return Math.min(loc1.x+1+loc2.x+1, size-1-loc1.x+size-1-loc2.x) + size;
			case 3 : return size-loc1.x + loc2.y;
			}
		case 1:  switch(edge2) {
			case 0 : return loc1.y+1 + loc2.x+1;
			case 1 : return Math.abs(loc1.y-loc2.y);
			case 2 : return size-loc1.y + loc2.x;
			case 3 : return Math.min(loc1.y+1+loc2.y+1, size-1-loc1.y+size-1-loc2.y) + size;
			}
		case 2: switch(edge2) {
			case 0 : return Math.min(loc1.x+1+loc2.x+1, size-1-loc1.x+size-1-loc2.x) + size;
			case 1 : return loc1.x + size - loc2.y;
			case 2 : return Math.abs(loc1.x-loc2.x);
			case 3 : return size-1-loc1.x + size-1-loc2.y;
			}
		case 3: switch(edge2) {
			case 0 : return loc1.y + size-loc2.x;
			case 1 : return Math.min(loc1.y+1+loc2.y+1, size-1-loc1.y+size-1-loc2.y) + size;
			case 2 : return size-1-loc1.y + size-1-loc2.x;
			case 3 : return Math.abs(loc1.y-loc2.y);
			}
		}
		return 0;
	}
	
	public static int getEdge(Location loc, long size)
	{
		if (loc.y <= -1)
			return 0;
		else if (loc.x <= -1)
			return 1;
		else if (loc.y >= size-1)
			return 2;
		else
			return 3;			
	}
}

class Location
{
	public int level;
	public long x, y;
	public long d;			// distance traveled to get to cooridor

	public Location(int level, long x, long y, long d)
	{
		this.level = level;
		this.x = x;
		this.y = y;
		this.d = d;
	}
	
	public boolean equals(Location other)
	{
		return (x == other.x && y == other.y);
	}
}
