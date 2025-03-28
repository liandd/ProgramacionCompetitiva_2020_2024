#include<bits/stdc++.h>
using namespace std;
int main(){
    int t=0;
    cin>>t;

    while(t--){
        int n=0;
        cin>>n;

        vector<int> v;

        for(int i=1; i<sqrt(n); i++){
            if(n%i==0){
                v.push_back(i);

                if(i!=n/i && n/i!=n){
                    v.push_back(n/i);
                }
            }
        }

        int s=0;
        for(int i=0; i<v.size(); i++){
            s+=v[i];
            //cout<<v[i];
        }

        if(s==n){
            cout<<n<<" eh perfeito\n";
        }else{
            cout<<n<<" nao eh perfeito\n";
        }


    }


    return 0;
}
