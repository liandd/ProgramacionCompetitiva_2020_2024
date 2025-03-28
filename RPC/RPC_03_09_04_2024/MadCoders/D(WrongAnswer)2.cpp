#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    if( n % 2 == 0){
        cout<< "Y";
    }else if ( n==1 | n%2 !=0){
        cout<<"N";
    }
    

    return 0;
}