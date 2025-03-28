#include<bits/stdc++.h>
using namespace std;
struct fila {
    std::vector<unsigned int> a;
    fila( unsigned int n) : a(n, 0) {}
};

int main() {
   unsigned int n, w;
    bool f=true;
    std::cin >> n >> w;

   unsigned int tam = (n % w == 0) ? n : n + (w - n % w);
   unsigned int t = tam / w;
    vector< unsigned int>sorner(n);
    for(unsigned int i=0; i<n; i++){
    std ::cin>>sorner[i];
    }
    sort(sorner.rbegin(), sorner.rend());

    std::vector<fila> filas(t, fila(w));
     unsigned int c = 0;
    for (unsigned int i = 0; i < t; i++) {
        for (unsigned int j = 0; j < w && c < n; j++, c++) {
            filas[i].a[j]=sorner[c];
        }
    }

    for(unsigned int j=0; j<w; j++){
       set<int>auxiliar;
       for(unsigned int i=0; i<t; i++) {
        if(auxiliar.find(filas[i].a[j]) != auxiliar.end() ){


        f=false;
        }
        auxiliar.insert(filas[i].a[j]);
       }

    }


    if(f){
    std::cout<<"yes\n";
    } else{
     std::cout<<"no\n";
    }

    return 0;
}
