#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t, n,d;
    cin>>t;
    while(t--){
        cin>>n;
        set <int> repeticiones;
        while(n--){
            cin>>d;
            repeticiones.insert(d);
        }
        cout<<repeticiones.size()<<"\n";
    }
}
