#include <bits/stdc++.h>

using namespace std;

int main(){
    
    vector<int> vec = {1, 2, 6, 24, 120, 720, 5040, 40320};
    int n, cont = 0;
    scanf("%d", &n);

    int i = 7; 

    while (n > 0 && i >= 0) {
        while (i >= 0 && vec[i] > n) {
            i--;
        }
        
        if (i < 0) break; 
        
        n -= vec[i];
        cont++;
    }
    
    printf("%d\n", cont);

    return 0;
}
