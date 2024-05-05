#include <bits/stdc++.h>
using namespace std;

int main(){
    int profs[10000];
    long long int opus[10000];
    int numProfes;

    cin>>numProfes;
    for(int i = 0; i < numProfes; i++) {
        cin>>opus[i];
        profs[i] = i + 1;
    }
    int c = 0;
    while (numProfes > 1) {
        int sigui = (c + opus[c] - 1) % numProfes;

        for(int i = sigui + 1; i < numProfes; i++) {
            opus[i-1] = opus[i];
            profs[i-1] = profs[i];
        }
        numProfes--;
        c = sigui % numProfes;
    }
    cout<<profs[0]<<endl;
}
