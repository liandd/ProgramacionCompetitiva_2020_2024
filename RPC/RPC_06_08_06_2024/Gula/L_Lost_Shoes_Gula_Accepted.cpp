#include <bits/stdc++.h>

using namespace std;

int movientos (vector <int>& v){
    int x= v.size();
    int cont=0;
    
    for (int i = 0; i < x; i++) {
        while (v[i] != i + 1) { 
            swap(v[i], v[v[i] - 1]);
            cont++;
        }
    }

    return cont;
}

int main(){
	
	int n;
	int z;
        scanf("%d", &n);
        vector <int> s;
        vector <int> t;
        for(int j=0; j<n; j++){
            scanf("%d", &z);
            s.push_back(z);
        }
        
        for(int j=0; j<n; j++){
            scanf("%d", &z);
            t.push_back(z);
        }
        int  r= movientos(s);
        r+= movientos(t);
        
        cout<<r<<"\n";
}