#include <bits/stdc++.h>

using namespace std;

string win(int p, int j1, int j2, int r, int a){
    if(r==1){
        if(a==1){
            return "Jogador 2 ganha!";
        }else return "Jogador 1 ganha!";
    }else{
        if(a==1){
            return "Jogador 1 ganha!";
        }else{
            int x=j1+j2;
            if(((x&1)==0 && p==1)||((x&1)== 1 && p==0)){
                return "Jogador 1 ganha!";
            }else return "Jogador 2 ganha!";
        }
    }
}


int main() {
    int p, j1, j2, r, a;
    scanf("%d%d%d%d%d", &p, &j1, &j2, &r, &a);
    
    cout<<win(p,j1,j2,r,a)<<"\n";
    
    return 0;
}