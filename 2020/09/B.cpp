#include <bits/stdc++.h>

using namespace std;

int main(){
    int millas, gasolina, comer, gasolina2 = 0, comer2 = 0;
    set<int> res;
    cin>>millas>>gasolina>>comer;
    while(gasolina2 < millas){
        gasolina2 += gasolina;
        if(gasolina2 >= millas)
            continue;
        res.insert(gasolina2);
    }
    while(comer2 < millas){
        comer2 += comer;
        if(comer2 >= millas)
            continue;
        res.insert(comer2);
    }
    cout<<res.size()<<endl;
    return 0;
}
