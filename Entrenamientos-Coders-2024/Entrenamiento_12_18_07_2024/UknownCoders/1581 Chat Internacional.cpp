#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=0;
    cin>>n;
    while(n--){
        int k=0;
        cin>>k;

        int c=0;
        string ars[k];

        for(int i=0; i<k; i++){
            cin>>ars[i];
            //cout<<ars[i];
            if(i>0 && ars[i]==ars[i-1]){
                c++;
            }
        }
        if(c==k-1){
            cout<<ars[0]<<"\n";
        }else{
            cout<<"ingles\n";
        }

    }

    return 0;
}
