#include<bits/stdc++.h>

using namespace std;

int main()
{
    int r, c, k;

    cin>>r>>c>>k;
    cin.ignore();
    vector <char> aux(c+1);
    vector <char> aux2(k+1);

    int banderaAux, banderaAux2;
    int resultado;

    for(int i = 0; i < r; i++){
        for (int j = 0; j<c; j++){
            cin.get(aux[j]);
            if(aux[j]=='-'){
                banderaAux = 1;
            }
        }
        cin.get();//espacio


        for (int h = 0; h < k; h++){
            cin.get(aux2[h]);
            if(aux2[h]=='*'){
                banderaAux2 = 1;
            }
        }
        cin.ignore();
        if(banderaAux == banderaAux2){
            resultado = 1;
        }
        banderaAux=0;
        banderaAux2=0;
    }

    if(resultado == 1){
        cout<<"N\n";
    }else{
        cout<<"Y\n";
    }

    return 0;
}
