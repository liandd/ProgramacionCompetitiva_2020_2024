#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b, c, con = 0;
    cin>>a>>b>>c;
    for(int i = a; i <= b; i++){
        int j = i;
        while(j > 0){
            if(j % 10 == c){
                con++;
            }
            j /= 10;
        }
    }
    cout<<con<<endl;
}
