#include<bits/stdc++.h>
using namespace std;

struct punto {
    int x, y;
};

//  área de un polígono convexo
double polygon_area(const vector<punto>& puntos) {
    int n = puntos.size();
    double area = 0.0;
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        area += puntos[i].x * puntos[j].y - puntos[j].x * puntos[i].y;
    }
    return fabs(area) / 2.0;
}

int main() {
    int n;
    cin >> n;
    vector<punto> vertices(n);
    for (int i = 0; i < n; ++i) {
        cin >> vertices[i].x >> vertices[i].y;
    }

    double min_diferencia = 1e9;

    // Iterar corte
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            vector<punto> poly1, poly2;

            for (int k = i; k <= j; ++k) {
                poly1.push_back(vertices[k]);
            }

            for (int k = j; k != i; k = (k + 1) % n) {
                poly2.push_back(vertices[k]);
            }
            poly2.push_back(vertices[i]);  // Cierra polígono

            double area1 = polygon_area(poly1);
            double area2 = polygon_area(poly2);
            double difference = fabs(area1 - area2);
            if (difference < min_diferencia) {
                min_diferencia = difference;
            }
        }
    }

    cout << fixed << setprecision(1) << min_diferencia << endl;
    return 0;
}
