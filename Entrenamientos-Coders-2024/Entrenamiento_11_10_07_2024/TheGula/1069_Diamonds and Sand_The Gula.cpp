#include <bits/stdc++.h>

using namespace std;

int res(string pal){
    int cont=0;
    int temp=0;
    for(int i=0; i<pal.size(); i++){

        if(pal[i]=='<'){
            temp++;
        }else if(pal[i]=='>' && temp> 0){
            cont++;
            temp--;
        }
    }
    return cont;
}


int main() {
    int n, l;
    scanf("%d", &n);
	cin.ignore();
    while(n--){
        string x;
        getline(cin,x);
        l=res(x);
        cout<<l<<"\n";
    }
    return 0;
}