#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
int main(){
    //fast
    string str;

    while(getline(cin,str)){

        int contador=0;

        for(int i=0; i<str.size(); i++){
            if(str[i]=='('){
                contador++;
            }else if(str[i]==')'){
                contador--;
            }

            if(contador<0){
                cout<<"incorrect\n";
                break;
            }
        }
        if(contador>0)cout<<"incorrect\n";
        else if(contador==0)cout<<"correct\n";

    }
    return 0;
}
