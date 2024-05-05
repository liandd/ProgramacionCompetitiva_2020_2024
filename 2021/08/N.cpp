#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    vector<int> total(6, 0);
    while(T--){
        vector<int> abc(6, 0);
        int n; cin>>n;
        for(int i = 0; i < n; i++){
            char aux; cin>>aux;
            total[aux - 65]++;
            abc[aux - 65]++;
        }
        cout<<"A:"<<abc[0]<<" B:"<<abc[1]<<" C:"<<abc[2]<<" D:"<<abc[3]<<" E:"<<abc[4]<<"F:"<<abc[5]<<"\n";
    }
    cout<<"TOTAL: A:"<<total[0]<<" B:"<<total[1]<<" C:"<<total[2]<<" D:"<<total[3]<<" E:"<<total[4]<<" F:"<<total[5]<<"\n";
    return 0;
}
