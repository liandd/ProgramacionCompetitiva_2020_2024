#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    char grid[8][8];
    while(true){
    int c=7, r=0;
    string cadena;
        cin>>cadena;
        for(int i=0; i<cadena.size(); i++){
            if(cadena[i]!='/'){
               if(cadena[i]>=49 && cadena[i]<=56){
                    for(int k=1; k<=cadena[i]-'0'; k++){
                        //cout<<"Entró r: "<<r<<" k: "<<k<<" i: "<<i<<endl;
                        grid[r][c]='0';
                        r++;
                        //cout<<"r: "<<endl;
                    }
               }else{
                    grid[r][c]=cadena[i];
                    r++;
               }
            }else{
                c--;
                r=0;
            }
            //cout<<"i: "<<i<<endl;
            //cout<<"c: "<<c<<endl;
            //cout<<"r: "<<r<<endl;
        }
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                cout<<grid[i][j];
            }
            cout<<"\n";
        }

    }
return 0;
}
