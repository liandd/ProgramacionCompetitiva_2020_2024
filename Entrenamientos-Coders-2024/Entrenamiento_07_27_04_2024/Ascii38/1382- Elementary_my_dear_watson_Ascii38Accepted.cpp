#include<bits/stdc++.h>
#define lli long long int 
using namespace std;
int main(){
    lli n;
    scanf("%lld", &n);
    while (n--){
        lli a, cont = 0;
        scanf("%lld", &a);
        lli array[a];

        for (int i  = 0; i < a; i++)
            scanf("%lld", &array[i]);
        
        for (int i = 0; i < a; 1){
            if (array[i] == i+1)
                i++;
            else{
                int tmp = array[array[i]-1];
                array[array[i]-1] = array[i];
                array[i] = tmp;
                cont++;
            }
        }
        printf("%lld\n", cont);
    }
    
    return 0;
}
