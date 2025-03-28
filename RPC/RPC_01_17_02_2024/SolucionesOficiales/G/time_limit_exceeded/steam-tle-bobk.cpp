#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//#define DEBUG 1

#define REPI(ctr,start,limit) for (int32_t ctr=(start);(ctr)<(limit);(ctr)++)

const double
    EPS = 1e-8;
const int32_t
    MAX_SEGS = 1000,
    MAX_CIRCLE = 4096;

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
    cloud[MAX_CIRCLE],
    camera,
    steamOrigin,steamEnd,
    velocity;
double
    radius;

bool intersect(Point p1,Point p2,Point q1,Point q2) {
    Point
        r = p2 - p1,
        s = q2 - q1,
        v = q1 - p1;
    double
        t,u,
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
        v;
    double
        best = 1E100,
        iTime;

    cin >> n;

    REPI(i,0,n+1)
        cin >> pList[i].x >> pList[i].y;

    cin >> camera.x >> steamOrigin.x >> steamOrigin.y >> radius >> velocity.x >> velocity.y >> v;

    velocity = velocity * (v / sqrt(velocity.x * velocity.x + velocity.y * velocity.y));

    REPI(i,0,n)
        if (pList[i].x <= camera.x && camera.x <= pList[i+1].x) {
            camera.y = pList[i].y + (pList[i+1].y - pList[i].y) * (camera.x - pList[i].x) /
                                            (pList[i+1].x - pList[i].x);
            break;
        }

    if (velocity.x == 0.0) {
        steamEnd.x = steamOrigin.x;
        steamEnd.y = 10000000.0;
    } else if (velocity.x < 0.0) {
        steamEnd = steamOrigin + velocity * ((-radius + pList[0].x - steamOrigin.x) / velocity.x);
    } else {
        steamEnd = steamOrigin + velocity * ((radius + pList[n].x - steamOrigin.x) / velocity.x);
    }

    REPI(i,0,MAX_CIRCLE) {
        cloud[i].x = radius * cos((2.0*M_PI*i)/MAX_CIRCLE) + steamOrigin.x;
        cloud[i].y = radius * sin((2.0*M_PI*i)/MAX_CIRCLE) + steamOrigin.y;
    }

    velocity = velocity * 0.0005;

    camera.y += 0.00001;

    iTime = 0;
    while (steamOrigin.y < steamEnd.y) {
        bool seeAny = false;
        REPI(i,0,MAX_CIRCLE) {
            bool seeThis = true;
            REPI(j, 0, n)
                if (intersect(camera, cloud[i], pList[j], pList[j + 1]))
                    seeThis = false;
            if (seeThis) {
                seeAny = true;
                break;
            }
        }
        if (seeAny) {
            best = iTime;
            break;
        }
        REPI(i,0,MAX_CIRCLE)
            cloud[i] = cloud[i] + velocity;
        steamOrigin = steamOrigin + velocity;
        iTime += 0.0005;
    }

    if (best == 1E100)
        best = -1;

    cout << setprecision(10) << best << endl;

    return 0;
}
