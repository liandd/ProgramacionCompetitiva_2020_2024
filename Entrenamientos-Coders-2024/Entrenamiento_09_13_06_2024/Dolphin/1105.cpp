#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n,b,d,c,s;
    bool ban=true;





    while(cin>>n>>b and n!=0 and b!=0){

        vector<int>v(n);

        for(int i=0;i<n;i++){
            cin>>v[i];
        }

         for(int i=0;i<b;i++){
              cin>>d>>c>>s;

              v[d-1]=v[d-1]-s;
              v[c-1]=v[c-1]+s;
        }

        for(int i=0;i<n;i++){

            if(v[i]<0){
                ban=false;
                break;
            }
        }

        if(ban==true){
            cout<<"S\n";
        }
        else{
            cout<<"N\n";
        }
        ban=true;
    }

    return 0;
}
