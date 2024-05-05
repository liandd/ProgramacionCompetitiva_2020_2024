#include <bits/stdc++.h>

using namespace std;

int main(){
     long long int tam = 0;
     cin>>tam;
     string vec[tam];
     long long int vecC[91] = {0};
     map<string,long long int> elQueLoLea;
     for(int i = 0; i < tam; i++){
         cin>>vec[i];
         vecC[vec[i][0]]++;
         elQueLoLea[vec[i]]++;
     }
     long long int subT = 0;
     for(int i = 65; i < 91; i++){
         if(vecC[i] > 1){
             subT+= (vecC[i] * (vecC[i] - 1));
         }
     }
     
long long int rest = 0;
     map<string,long long int>::iterator puto;
     for(puto = elQueLoLea.begin(); puto != elQueLoLea.end(); puto++){
         if(puto->second > 1){
             rest += (puto->second * (puto->second - 1));
         }
     }
     cout<<subT-rest<<endl;
     return 0;
}