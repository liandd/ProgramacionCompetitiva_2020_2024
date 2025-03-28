#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
int main(){
    //fast
    int q=0;
    cin>>q;

    while(q--){
        int n=0, t=0;
        cin>>n>>t;
        t=t-1;

        vector<int> v;

        for(int i=1; i<=sqrt(t); i++){
            if(t%i==0 && n>=i){
                v.push_back(i);

                if(i!=t/i && n>=(t/i)){
                    v.push_back(t/i);
                }
            }
        }

        /*for(int i=0; i<v.size(); i++){
            cout<<v[i]<<"\n";

        }*/

        if(v.size()==0){
            cout<<n<<"\n";
        }else{
            cout<<v.size()<<"\n";
        }
    }

    return 0;
}
