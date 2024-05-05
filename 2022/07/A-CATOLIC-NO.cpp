#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin>>arr[i];
    
    int primero = arr[0];
    int solve = 0;
    while(true){
        bool canPass = true;
        vector<int> copia = arr;
        copia[0] = primero + solve;
        for(int j = 1; j < n; j++) copia[j] += copia[j - 1];
        for(int j = 0; j < n; j++){
            if(copia[j] < 0){
                canPass = false;
                break;
            }
        }
            
        if(canPass){
            cout<<solve<<endl;
            return 0;
        }else solve++;
    }

    return 0;
}