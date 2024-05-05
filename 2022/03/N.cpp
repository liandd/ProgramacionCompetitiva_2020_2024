#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, r, cr=0, cd=0;
    cin>>n>>r;
    while(n--){
        int salario;
        cin>>salario;
        if (salario*2>salario+r){
            cd++;
        }else if(salario*2<salario+r){
            cr++;
        }
    }
    if (cr>cd){
        cout<<"1\n";
    }else if (cr<cd){
        cout<<"2\n";
    }else{
        cout<<"0\n";
    }
    
    
    
    return 0;
}