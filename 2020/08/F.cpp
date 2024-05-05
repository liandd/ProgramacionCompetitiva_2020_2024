#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        long long int x, tmp = 1;
        scanf("%lld", &x);
        tmp = ((x + 1) * (x + 1)) - 1;
        printf("%lld\n", tmp);
    }
    return 0;
}
