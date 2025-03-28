// Arup Guha
// 8/26/2023
// Solution to UCF Locals 2023 Qualifying Round Problem: Cut the Cake

using namespace std;
#include <bits/stdc++.h>

int main() {

    // Read in the points.
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    for (int i=0; i<n; i++)
        cin >> x[i] >> y[i];

    // Get whole area (twice of it).
    int dWhole = 0;
    for (int i=0; i<n; i++)
        dWhole += (x[i]*y[(i+1)%n]-x[(i+1)%n]*y[i]);
    dWhole = abs(dWhole);

    // Answer is smaller than this.
    int dDiff = 2000000;

    // i is where we start the cut.
    for (int i=0; i<n; i++) {

        // j is where we end the cut.
        for (int j=i+2; j<n; j++) {

            // This is not a valid cut.
            if (i == 0 && j == n-1) continue;

            // Calculate the area of this polygon, from i to j and back.
            int thisD = 0;
            for (int k=i; k<j; k++)
                thisD += (x[k]*y[(k+1)%n]-x[(k+1)%n]*y[k]);
            thisD += (x[j]*y[i]-x[i]*y[j]);

            // This is double the area of this polygon.
            thisD = abs(thisD);

            // Get the rest.
            int other = dWhole - thisD;

            // Take the difference.
            int tmp = abs(thisD - other);

            // Update if necessary.
            dDiff = min(dDiff, tmp);
        }
    }

    // Ta da!
    printf("%.1f\n", dDiff/2.0);
    return 0;
}
