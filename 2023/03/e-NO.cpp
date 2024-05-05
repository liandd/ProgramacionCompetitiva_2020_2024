#include<bits/stdc++.h>
using namespace std;
int main() {
    int w=0, h=0, x=0, y=0;
    cin>>w>>h>>x>>y;
    if(w == 1 && h == 1) {
        cout << "Lose\n";
        return 0;
    }
    if((w & 1 && x == (w + 1) / 2) || (h & 1 && y == (h + 1) / 2)) {
        cout << "Win\n";
    }
    else{
        cout << "Lose\n";
    }
    return 0;
}
