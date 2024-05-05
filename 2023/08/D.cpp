#include<bits/stdc++.h>

using namespace std;

struct Point {
    int x;
    int y;
};

bool isInsideSquare(const Point& point, int side, int x, int y) {
    return (point.x >= x && point.x <= x + side && point.y >= y && point.y <= y + side);
}

int main() {
    int s, n;
    cin >> s >> n;

    vector<Point> fish(n);
    for (int i = 0; i < n; i++) {
        cin >> fish[i].x >> fish[i].y;
    }

    int maxFish = 0;
    for (int x = 1; x <= 100 - s + 1; x++) {
        for (int y = 1; y <= 100 - s + 1; y++) {
            int fishCount = 0;
            for (int i = 0; i < n; i++) {
                if (isInsideSquare(fish[i], s, x, y)) {
                    fishCount++;
                }
            }
            maxFish = max(maxFish, fishCount);
        }
    }

    cout << maxFish << "\n";

    return 0;
}
