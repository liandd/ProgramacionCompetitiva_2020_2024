#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        int x, tmp = 1;
        cin>>x;
        for(int i = 2; i <= x / 2; i++){
            if(x % i == 0)
                tmp += i;
        }
        if(tmp < x){
            cout<<"deficient"<<endl;
        }else if (tmp == x){
            cout<<"perfect"<<endl;
        }else{
            cout<<"abundant"<<endl;
        }
    }
    return 0;
}
