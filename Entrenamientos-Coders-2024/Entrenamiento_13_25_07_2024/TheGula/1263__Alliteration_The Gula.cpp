#include <bits/stdc++.h>

using namespace std;

void contar(vector<string> xx) {

	int gcont=0;
	int acont=0;

	for(int i=1; i<xx.size(); i++) {
		if(xx[i][0] == xx[i-1][0]) {
			acont++;
		} else {
			if(acont>=1) {
				gcont++;
			}
			acont=0;
		}
	}

	if (acont >= 1) {
		gcont++;
	}

	printf("%d\n",gcont);


}

+void separar(string ora) {
	vector<string> xx;
	string aux="";
	for(int i=0; i<ora.size(); i++) {
		if(ora[i] !=' ') {
			aux+=ora[i];
		} else {
			transform(aux.begin(), aux.end(), aux.begin(), ::tolower);
			xx.push_back(aux);
			aux="";
		}
	}


	if(!aux.empty()) {
		transform(aux.begin(), aux.end(), aux.begin(), ::tolower);
		xx.push_back(aux);
	}



	/*for (auto i: xx) {
		cout << i << "\n";
	}*/

	contar(xx);
}



int main() {
	string oracion="";


	while(getline(cin, oracion)) {
		separar(oracion);
	}
	return 0;
}