#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=0, t=0, a=0, b=0, c=0;
    cin>>n>>t;
    char l;
    vector<bool> d(n+1, true);
    for(int i=0; i<t; i++){
        cin>>l;
        if(l=='A'){
         cin>>a>>b;
         int cont=0;
         for(int j=a; j<=b; j++){
            if(d[j]==true){
                cont++;
            }

        }

            cout<<cont<<"\n";
    }else{
         cin>>c;
         d[c]=false;
    }


}



    return 0;
}
