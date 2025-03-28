#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Location
{
public:
	int level;
	long long x, y;
	long long d;			// distance traveled to get to cooridor

	Location(int lev, long long xx, long long yy, long long dd) : level(lev), x(xx), y(yy), d(dd)
	{
	}
};

bool locEquals(Location* l1, Location *l2)
{
    return (l1->x == l2->x && l1->y == l2->y);
}

vector<Location*> getPath(long long x, long long y, int level);
vector<Location*> extendToExterior(vector<Location*> path);
long long getExteriorDistance(Location* loc1, Location* loc2, long long hsize);
int getEdge(Location* loc, long long hsize);

int main() {

    int k;
    long long x1, y1, x2, y2, hsize, extraDist = 0;
    int level;
    vector<Location*> path1, path2;

    cin >> k;
    for(int i=1; i<=k; i++) {
        cin >> level >> x1 >> y1 >> x2 >> y2;
        hsize = (long long) pow(2,  level);
        extraDist = 0;
        if (x1<=-1 && x2 <=-1 ||					// special cases
            x1 >=hsize-1 && x2 >= hsize-1 ||
            y1<=-1 && y2 <=-1 ||
            y1 >=hsize-1 && y2 >= hsize-1) {
            cout << abs(x1-x2) + abs(y1-y2) << endl;
            continue;
        }
        else if (x1 == x2 && y1 == y2) {
            cout << 0 << endl;
            continue;
        }
        if (x1 < -1) {						// move point 1 to edge of hedge if necessary
            extraDist += -1-x1;
            x1 = -1;
        }
        else if (x1 > hsize-1) {
            extraDist += x1 - (hsize-1);
            x1 = hsize-1;
        }
        if (y1 < -1) {
            extraDist += -1-y1;
            y1 = -1;
        }
        else if (y1 > hsize-1) {
            extraDist += y1 - (hsize-1);
            y1 = hsize-1;
        }
        if (x2 < -1) {						// move point 2 to edge of hedge if necessary
            extraDist += -1-x2;
            x2 = -1;
        }
        else if (x2 > hsize-1) {
            extraDist += x2 - (hsize-1);
            x2 = hsize-1;
        }
        if (y2 < -1) {
            extraDist += -1-y2;
            y2 = -1;
        }
        else if (y2 > hsize-1) {
            extraDist += y2 - (hsize-1);
            y2 = hsize-1;
        }
//System.out.println(x1 + " " + y1 + " " + x2 + " " + y2 + " " + extraDist);
        path1 = getPath(x1, y1, level);
        path1 = extendToExterior(path1);
//for(Location* loc : path1) {
//cout << loc->level << " (" << loc->x << "," << loc->y << ") " << loc->d << endl;
//}
        path2 = getPath(x2, y2, level);
        path2 = extendToExterior(path2);
//for(Location* loc : path2) {
//cout << loc->level << " (" << loc->x << "," << loc->y << ") " << loc->d << endl;
//}
        if (!locEquals(path1[0],path2[0]))
            cout << getExteriorDistance(path1[0], path2[0], pow(2,level)) + path1[0]->d + path2[0]->d + extraDist << endl;
        else {
            int i1=0, i2=0;
            while (i1 < path1.size()-1 && i2 < path2.size()-1 && locEquals(path1[i1], path2[i2])) {
//					level = path1.get(i1).level;
//					if (path1.get(++i1).level == level)
                    i1++;
//					level = path1.get(i2).level;
//					if (path2.get(++i2).level == level)
                    i2++;
            }
            long long dist = path1[i1]->d + path2[i2]->d
                    + abs(path1[i1]->x-path2[i2]->x) + abs(path1[i1]->y-path2[i2]->y);
            cout << dist + extraDist << endl;        }
    };
}

vector<Location*> getPath(long long x, long long y, int level)
{
    vector<Location*> ans;
//cout << "call: " << x << "," << y << "," << level<< endl;
    long long d = 0;
    if (level == 1) {
        if (x == 0 && y == 0) {			// only distance need traveled for base case
            d = 1;
            y = -1;
        }
        ans.push_back(new Location(level,x,y,d));
        return ans;
    }
    // determine which quadrant (x,y) falls in    2 | 3
    //                                           ---+---
    //                                            0 | 1
    long long hsize = pow(2,level);
    int quad = 0;
    if (x >= hsize/2)
        quad++;
    if (y >= hsize/2)
        quad += 2;
    // convert (x, y) to point relative to quadrant
    long long newx, newy;
    switch (quad) {
    case 0: newx = hsize/2 - 2 - y;
    newy = x;
    break;
    case 1: newx = y;
    newy = hsize - 2 - x;
    break;
    case 2: newx = x;
    newy = y - hsize/2;
    break;
    default: newx = x - hsize/2;
    newy = y - hsize/2;
    }
    ans = getPath(newx, newy, level-1);
    Location* l = ans[0];
//System.out.println("level = " + level + " (" + l.x + "," + l.y + ") " + l.d + " hsize = " + hsize);
    d = l->d;
    newx = l->x;
    newy = l->y;
    if (newx > -1 && newx < hsize/2-1 && newy > -1 && newy < hsize/2-1) {		// point in interior
        if (newy <= hsize/4-1) {
            d += abs(hsize/4-1-newx);
            newx = hsize/4-1;
            ans.insert(ans.begin(), new Location(level,newx, newy, d));
            d += newy+1;
            newy = -1;
        }
        else {
            d += hsize/2 - 1 - newy;
//				newx = hsize/4;
            newy = hsize/2-1;
        }
    }
//System.out.println("  add (" + newx + "," + newy + ") " + d);
    ans.insert(ans.begin(), new Location(level,newx,newy,d));

    for(Location* loc : ans) {		// convert to local coordinates
        switch (quad) {
        case 0: x = loc->y;
        y = hsize/2 - 2 - loc->x;
        break;
        case 1: x = hsize - 2 - loc->y;
        y = loc->x;
        break;
        case 2: x = loc->x;
        y = loc->y + hsize/2;
        break;
        default: x = loc->x + hsize/2;
        y = loc->y + hsize/2;
        }
//System.out.print("("+loc->x+","+loc->y+") --> (" + x + "," + y + ")");
        loc->x = x;
        loc->y = y;
    }
//System.out.println();
    return ans;
}

vector<Location*> extendToExterior(vector<Location*> path)
{
    long long newx = path[0]->x;
    long long newy = path[0]->y;
    long long d = path[0]->d;
    int level = path[0]->level;
    long long hsize = pow(2,level);
    if (newx > -1 && newx < hsize-1 && newy > -1 && newy < hsize-1) {		// add point to get to exterior if necessary
        if (newy <= hsize/2-1) {
            d += abs(hsize/2-1-newx);
            newx = hsize/2-1;
            path.insert(path.begin(), new Location(level+1,newx, newy, d));
            d += newy+1;
            newy = -1;
        }
        else {
//System.out.println("here:" + hsize + " " + newx + " " + newx);
            d += hsize-1 - newy;
//				newx = hsize/2;
            newy = hsize-1;
        }
    }
    path.insert(path.begin(), new Location(level+1,newx,newy,d));
    return path;
}

long long getExteriorDistance(Location* loc1, Location* loc2, long long hsize)
{
    int edge1 = getEdge(loc1, hsize);
    int edge2 = getEdge(loc2, hsize);
    switch (edge1) {
    case 0: switch(edge2) {
        case 0 : return abs(loc1->x-loc2->x);
        case 1 : return loc1->x+1 + loc2->y+1;
        case 2 : return min(loc1->x+1+loc2->x+1, hsize-1-loc1->x+hsize-1-loc2->x) + hsize;
        case 3 : return hsize-loc1->x + loc2->y;
        }
    case 1:  switch(edge2) {
        case 0 : return loc1->y+1 + loc2->x+1;
        case 1 : return abs(loc1->y-loc2->y);
        case 2 : return hsize-loc1->y + loc2->x;
        case 3 : return min(loc1->y+1+loc2->y+1, hsize-1-loc1->y+hsize-1-loc2->y) + hsize;
        }
    case 2: switch(edge2) {
        case 0 : return min(loc1->x+1+loc2->x+1, hsize-1-loc1->x+hsize-1-loc2->x) + hsize;
        case 1 : return loc1->x + hsize - loc2->y;
        case 2 : return abs(loc1->x-loc2->x);
        case 3 : return hsize-1-loc1->x + hsize-1-loc2->y;
        }
    case 3: switch(edge2) {
        case 0 : return loc1->y + hsize-loc2->x;
        case 1 : return min(loc1->y+1+loc2->y+1, hsize-1-loc1->y+hsize-1-loc2->y) + hsize;
        case 2 : return hsize-1-loc1->y + hsize-1-loc2->x;
        case 3 : return abs(loc1->y-loc2->y);
        }
    }
    return 0;
}

int getEdge(Location* loc, long long hsize)
{
    if (loc->y <= -1)
        return 0;
    else if (loc->x <= -1)
        return 1;
    else if (loc->y >= hsize-1)
        return 2;
    else
        return 3;
}
