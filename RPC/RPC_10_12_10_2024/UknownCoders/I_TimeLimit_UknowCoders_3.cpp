#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
int main(){
    fast
    int n=0, t=0, a=0, b=0, c=0, h=0;
    cin>>n>>t;
    char l;

    stack<int> d;
    stack<int> d2;
    for(int i=0; i<t; i++){

        cin>>l;
        if(l=='A'){
            cin>>a>>b;
            int w=(b-a)+1;
            d=d2;
            for(int j=0; j<h && !d.empty(); j++){
                if(d.top()>=a && d.top()<=b){
                    w--;
                    d.pop();
                }else{
                    d.pop();
                }
            }
            cout<<w<<"\n";
        }else{
            cin>>c;
            d2.push(c);
            h++;
        }
    }

    return 0;
}
