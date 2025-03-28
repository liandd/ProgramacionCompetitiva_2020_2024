#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//#define DEBUG 1

#define REPI(ctr,start,limit) for (int32_t ctr=(start);(ctr)<(limit);(ctr)++)

const double
    EPS = 1e-8;
const int32_t
    MAX_SEGS = 1000;

struct Point {
    double
        x{},y{};
    explicit Point(double xx=0.0,double yy=0.0) { x = xx; y = yy;}
    Point operator+(Point rhs) const { return Point(x+rhs.x,y+rhs.y); }
    Point operator-(Point rhs) const { return Point(x-rhs.x,y-rhs.y); }
    Point operator*(double r) const { return Point(x*r,y*r); }
    double operator*(Point rhs) const { return x*rhs.y - y*rhs.x; }
};

int32_t
    n;
Point
    pList[MAX_SEGS+1],
    camera,
    steamOrigin,steamEnd,
    velocity;
double
    radius,
    low,high;

bool intersect(Point p1,Point p2,Point q1,Point q2,double &t,double &u) {
    Point
        r = p2 - p1,
        s = q2 - q1,
        v = q1 - p1;
    double
        d = r * s;

    if (fabs(d) < EPS)
        return false;

    t = (v * s) / d,
    u = (v * r) / d;

    if (t >= 0.0 && t <= 1.0 && u >= 0.0 && u <= 1.0)
        return true;

    return false;
}

int main() {
    int32_t
        v,
        leftCur=0,rightCur=0,
        tmp=0;
    Point
        p1, p2,
        dr;
    bool
        needed[MAX_SEGS+1];
    double
        tt,uu,
        best = 1E100,
        iTime;

    cin >> n;

    REPI(i,0,n+1) {
        cin >> pList[i].x >> pList[i].y;
        needed[i] = false;
    }

    cin >> camera.x >> steamOrigin.x >> steamOrigin.y >> radius >> velocity.x >> velocity.y >> v;

    velocity = velocity * (v / sqrt(velocity.x * velocity.x + velocity.y * velocity.y));

    REPI(i,0,n)
        if (pList[i].x <= camera.x && camera.x <= pList[i+1].x) {
            camera.y = pList[i].y + (pList[i+1].y - pList[i].y) * (camera.x - pList[i].x) /
                                            (pList[i+1].x - pList[i].x);
            if (pList[i].x == camera.x) {
                needed[i] = true;
                if (i > 0)
                    needed[i-1] = true;
                if (i < n)
                    needed[i+1] = true;
                leftCur = i - 1;
                rightCur = i + 1;
            } else {
                needed[i] = needed[i+1] = true;
                leftCur = i;
                rightCur = i + 1;
            }
            break;
        }

    for (int32_t i=leftCur-1;i>=0;i--) {
        if ((pList[leftCur]-camera) * (pList[i]-camera) <= 0.0) {
            needed[i] = true;
            if (!needed[i+1]) {
                intersect(camera,pList[leftCur],pList[i+1],pList[i],tt,uu);
                if (uu != 1.0) {
                    pList[i + 1] = pList[i + 1] + (pList[i] - pList[i + 1]) * uu;
                    needed[i + 1] = true;
                }
            }
            leftCur = i;
        }
    }
    REPI(i,rightCur+1,n+1) {
        if ((pList[rightCur]-camera) * (pList[i]-camera) >= 0.0) {
            needed[i] = true;
            if (!needed[i-1]) {
                intersect(camera,pList[rightCur],pList[i-1],pList[i],tt,uu);
                pList[i-1] = pList[i-1] + (pList[i] - pList[i-1]) * uu;
                needed[i-1] = true;
            }
            rightCur = i;
        }
    }

    low = pList[0].x;
    high = pList[n].x;

    p1.x = pList[n].x;
    p1.y = camera.y + (pList[rightCur].y - camera.y) * (high - camera.x) /
                              (pList[rightCur].x - camera.x);
    if (!needed[0]) {
        pList[0].y = camera.y + (pList[leftCur].y - camera.y) * (low - camera.x) / (pList[leftCur].x - camera.x);
        tmp = 1;
    }
    REPI(i,0,n+1)
        if (needed[i])
            pList[tmp++] = pList[i];
    if (!needed[n]) {
        pList[tmp] = p1;
        tmp++;
    }
    n = tmp;
    if (pList[0].y < 0)
        pList[0].y = 0;
    if (pList[n-1].y < 0)
        pList[n-1].y = 0;

    if (velocity.x == 0.0) {
        steamEnd.x = steamOrigin.x;
        steamEnd.y = 10000000.0;
    } else if (velocity.x < 0.0)
        steamEnd = steamOrigin + velocity * ((-radius + low - steamOrigin.x) / velocity.x);
    else
        steamEnd = steamOrigin + velocity * ((radius + high - steamOrigin.x) / velocity.x);

#ifdef DEBUG
    cout << "Camera at " << camera.x << ',' << camera.y << endl;
    cout << "Tangent 1 at " << p1.x << ',' << p1.y << endl;
    cout << "Tangent 2 at " << p2.x << ',' << p2.y << endl;
    cout << "Velocity " << velocity.x << ',' << velocity.y << endl;
    cout << "Steam start " << steamOrigin.x << ',' << steamOrigin.y << endl;
    cout << "Steam end " << steamEnd.x << ',' << steamEnd.y << endl;

    //    cout << "Edge 1 start " << steamEdge1[0].x << ',' << steamEdge1[0].y << endl;
//    cout << "Edge 1 end " << steamEdge1[1].x << ',' << steamEdge1[1].y << endl;
//    cout << "Edge 2 start " << steamEdge2[0].x << ',' << steamEdge2[0].y << endl;
//    cout << "Edge 2 end " << steamEdge2[1].x << ',' << steamEdge2[1].y << endl;

    cout << "Needed points:" << endl;
    REPI(i,0,n)
        cout << pList[i].x << ',' << pList[i].y << endl;
#endif

    REPI(i,0,n-1) {
#ifdef DEBUG
        cout << "Segment " << i << endl;
#endif
        dr.x = (pList[i+1] - pList[i]).y;
        dr.y = (pList[i] - pList[i+1]).x;
        dr = dr * (radius / sqrt(dr.x * dr.x + dr.y * dr.y));
        p1 = pList[i] + dr;
        p2 = p1 + (pList[i+1] - pList[i]);

#ifdef DEBUG
        cout << "start at " << p1.x << ',' << p1.y << endl;
        cout << "end at " << p2.x << ',' << p2.y << endl;
#endif

        if (intersect(p1,p2,steamOrigin,steamEnd,tt,uu)) {
            iTime = (steamEnd.y - steamOrigin.y) * uu / velocity.y;
            if (iTime < best)
                best = iTime;
#ifdef DEBUG
            cout << "Intersect at time " << iTime << endl;
#endif
        }
#ifdef DEBUG
        else
            cout << "No intersect" << endl;
#endif
    }

    double
        lineA = steamEnd.y - steamOrigin.y,
        lineB = steamOrigin.x - steamEnd.x,
        a2b2 = lineA * lineA + lineB * lineB;

    REPI(i,0,n) {
        double
            lineC = -(lineA * (steamOrigin.x - pList[i].x) + lineB * (steamOrigin.y - pList[i].y)),
            d0 = fabs(lineC) / sqrt(a2b2);

        if (d0 > radius) {
#ifdef DEBUG
            cout << "No intersect" << endl;
#endif
            continue;
        }

        double
            x0 = -lineA * lineC / a2b2,
            y0 = -lineB * lineC / a2b2,
            d = sqrt(radius * radius - lineC * lineC / a2b2),
            m = sqrt(d * d / a2b2);

        p1.x = x0 + lineB * m;
        p1.y = y0 - lineA * m;
        p2.x = x0 - lineB * m;
        p2.y = y0 + lineA * m;

        if (p1.y > p2.y) {
            p1.y = p2.y;
            p1.x = p2.x;
        }

        iTime = (p1.y + pList[i].y - steamOrigin.y) / velocity.y;
        if (iTime >= 0 && iTime < best)
            best = iTime;
#ifdef DEBUG
        cout << "Intersect at time " << iTime << " at " << (p1.x + pList[i].x) << ',' << (p1.y + pList[i].y) << endl;
#endif
    }

    if (best == 1E100)
        best = -1;

    cout << setprecision(10) << best << endl;

    return 0;
}
