#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace boost::multiprecision;

int main() {
    cpp_int p, n;
    cin >> p;
    cin >> n;

    cpp_int d = p - (n*n);
    if(d<=0){
        cout <<0<< "\n";
    }else{
        cout <<d<< "\n";
    }

    return 0;
}
