#include <bits/stdc++.h>
using namespace std;

int main(){
	vector <string> vec;
	int TAM;
	string cadena;
	map <char, int> datos;
	datos['I'] = 1;
	datos['V'] = 5;
	datos['X'] = 10;
	datos['L'] = 50;
	datos['C'] = 100;
	datos['D'] = 500;
	datos['M'] = 1000;

	cin >> TAM;

	for(int i= 0; i<TAM; i++){
		cin >> cadena;
		vec.push_back(cadena);
	}


	int resta= 0;
	for (auto i: vec){
		if(i.size() % 2 == 0){
			resta = 0;
			for(int j=0; j<i.size(); j+=2){
				int a, b;

				a = datos[i[j]];
				b = datos[i[j+1]];
				resta += b-a;

			}
			cout << resta<<"\n";
		}else{
		     int suma = 0;
		    for(int k =1; k<i.size(); k++){
                if(i[k-1] == i[k]){
                    suma += datos[i[k-1]];


                }else{
                    // cout << suma << "\n";
                    suma = datos[i[k]] - suma-1;
                    //cout << datos[i[k]]<< "\n";

                }
		    }
		    cout << suma<<"\n";

		}
	}
	return 0;
}
