#include <bits/stdc++.h>
using namespace std;

int main(){
    int x1, y1, x2, y2;
    double salida, meta;
    cin>>x1>>y1>>x2>>y2;
    salida = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
    cin>>x1>>y1>>x2>>y2;
    meta = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
    cout<<fixed<<setprecision(10)<< max(salida, meta) <<"\n";
    return 0;
}
