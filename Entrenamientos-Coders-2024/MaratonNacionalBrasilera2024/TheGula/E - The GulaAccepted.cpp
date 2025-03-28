#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, minx=1000000;
	int vJ,vI;
	cin>>n;

	int num[n][n];
	int aux[n][n];

	for(int i=0; i<n; i++){
        for(int j=0; j<n;j++){
            cin>>num[i][j];
            minx=min(minx, num[i][j]);
        }
	}

/*	for(int i=0; i<n; i++){
        for(int j=0; j<n;j++){
            cout<<i<<" "<<j<<": "<<num[i][j]<<"\n";
        }
	}*/


	for(int i=0; i<n; i++){
        for(int j=0; j<n;j++){
            if(minx==num[i][j]){
                vJ=j;
                vI=i;
                break;
            }
        }
	}

	// cout<<vI<<" "<<vJ<<"min:" <<minx<<"\n";
    //Filas I Columnas J
    if(vJ==0 && vI==0){
        cout<<"0\n";
    }else if(vI==0 && vJ==n-1){
        cout<<"1\n";
    }else if(vI==n-1 && vJ==n-1){
        cout<<"2\n";
    }else if(vI==n-1 && vJ==0){
        cout<<"3\n";
    }


	return 0;
}
