#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
    for(int i=n-1; i>=1; i--){
        n*=i;
    }
    return n;
}


int main(){
    int n=0;
    cin>>n;
    int c=0;

    int ar[8];
    for(int i=0; i<8; i++){
        ar[i]=factorial(i+1);
        //cout<<ar[i]<<" ";
    }

    for(int i=7; i>=0; i--){
        if(n>=ar[i]){
            //cout<<n<<" "/*<<ar[i]<<" "*/;
            n-=ar[i];
            //cout<<n<<" ";
            c++;
            i++;
            if(n==0){
                break;
            }
        }
    }

    cout<<c<<"\n";

    return 0;
}
