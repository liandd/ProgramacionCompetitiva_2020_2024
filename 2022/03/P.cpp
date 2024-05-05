#include <bits/stdc++.h>
using namespace std;

long long digitSum(string num){
    long long suma = 0;
    for(int i = 0; i < num.length(); i++){
        suma += (num[i] - '0');
    }
    return suma;
}

int main(){
    string a, b;
    cin>>a>>b;
    long long w_a = a.length() * digitSum(a);
    long long w_b = b.length() * digitSum(b);

    if(w_a > w_b) cout<<1<<endl;
    else if(w_a < w_b) cout<<2<<endl;
    else  cout<<0<<endl;
    return 0;
}
