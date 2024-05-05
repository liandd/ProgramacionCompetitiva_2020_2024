#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;
const int MAXD = 10000;
const double INF = 10*MAXD*MAXD;

struct point {
    double x, y;
};

point judges[MAX], tar[MAX], feather[MAX];
bool usedJ[MAX], usedT[MAX], usedF[MAX];
int nJudge, nTar, nFeath;

int main(){
    cin >> nJudge >> nTar >> nFeath;
    for(int i=0; i<nJudge; i++) {
        cin >> judges[i].x >> judges[i].y;
        usedJ[i] = false;
    }
    for(int i=0; i<nTar; i++) {
        cin >> tar[i].x >> tar[i].y;
        usedT[i] = false;
    }
    for(int i=0; i<nFeath; i++) {
        cin >> feather[i].x >> feather[i].y;
        usedF[i] = false;
    }
    double total = 0.0;
    for(int i=0; i<nJudge; i++) {
        double minDist = INF;
        int savj, savk;
        for(int j=0; j<nJudge; j++) {
            if (usedJ[j]) continue;
            for(int k=0; k<nTar; k++) {
                if (usedT[k]) continue;
                double xdiff = judges[j].x-tar[k].x;
                double ydiff = judges[j].y-tar[k].y;
                double dist = xdiff*xdiff + ydiff*ydiff;
                if (dist < minDist) {
                    minDist = dist;
                    savj = j;
                    savk = k;
                }
            }
        }
        total += sqrt(minDist);
        usedJ[savj] = true;
        usedT[savk] = true;
    }
    for(int i=0; i<nJudge; i++) {
        usedJ[i] = false;
    }
    for(int i=0; i<nJudge; i++) {
        double minDist = INF;
        int savj, savk;
        for(int j=0; j<nJudge; j++) {
            if (usedJ[j]) continue;
            for(int k=0; k<nFeath; k++) {
                if (usedF[k]) continue;
                double xdiff = judges[j].x-feather[k].x;
                double ydiff = judges[j].y-feather[k].y;
                double dist = xdiff*xdiff + ydiff*ydiff;
                if (dist < minDist) {
                    minDist = dist;
                    savj = j;
                    savk = k;
                }
            }
        }
        total += sqrt(minDist);
        usedJ[savj] = true;
        usedF[savk] = true;
    }
    cout << fixed << setprecision(6) << total << endl;
}
