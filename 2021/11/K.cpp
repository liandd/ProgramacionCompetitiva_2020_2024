#include <bits/stdc++.h>
using namespace std;

struct knot{
    int number;
    bool isKnow;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<knot> nudos(n);
    for(int i = 0; i < n; i++){
        cin>>nudos[i].number;
        nudos[i].isKnow = false;
    }

    for(int i = 0; i < n - 1; i++){
        int aux;
        cin>>aux;
        for(int j = 0; j < n; j++)
            if(nudos[j].number == aux)
                nudos[j].isKnow = true;
    }
    for(int i = 0; i < n; i ++)
    if(!nudos[i].isKnow){
        cout<<nudos[i].number<<"\n";
        break;
    }
    return 0;
}
