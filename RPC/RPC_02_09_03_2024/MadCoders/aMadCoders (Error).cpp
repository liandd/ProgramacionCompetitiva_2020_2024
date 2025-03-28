#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, k;
    double aux;
    double sumaP=0;
    double resultado;
    
    cin >> n >> m >> k;
    
    vector<int> tamano;
    
    while(n--){
        cin >> aux;
        sumaP += aux;
        tamano.push_back(aux);
    }
    sort(tamano.rbegin(), tamano.rend()); 
    
    int suma = 0;
    for (int i = 0; i <m+k; i++) {
        suma += tamano[i];
    }
    
    resultado = (suma/sumaP)*100;
    cout<<resultado<<endl;

    return 0;
}
