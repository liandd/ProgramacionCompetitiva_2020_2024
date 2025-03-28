#include<bits/stdc++.h>
using namespace std;

int main(){

    long long N=0, K=0, S=0, cont=0, i;
    cin>>N>>K;

    for(i=1; i<N; i++){

        S=i*K+1;

        if(S<=N){
          cont++;
        }

    }

    cout<<cont<<"\n";

    return 0;
}
