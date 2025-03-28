#include<bits/stdc++.h>

using namespace std;

int main(){
    int cont = 1, v, i;
    vector<int> billetes(4, 0);
    vector<int> denominaciones(4, 0);
    denominaciones[0] = 50;
    denominaciones[1] = 10;
    denominaciones[2] = 5;
    denominaciones[3] = 1;
    while(cin>>v){
        if(!v) return 0;
        i = 0;
        while(v){
            if(v>=denominaciones[i]){
                int aux = floor(v/denominaciones[i]);
                billetes[i] = aux;
                v-=(aux*denominaciones[i]);
            }else i++;
        }
        printf("Teste %d\n", cont);
        for(int j=0; j<billetes.size(); j++){
            printf("%d", billetes[j]);
            if(j<3) printf(" ");
            else printf("\n\n");
        }
        cont++;
        billetes.assign(4, 0);
    }

return 0;
}
