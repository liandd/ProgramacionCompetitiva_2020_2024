#include <bits/stdc++.h>

using namespace std;

bool existe(char a,	vector<pair<char,int>> b) {

	for(auto i: b) {
		if(a==i.first) {
			return true;
		}
	}

	return false;
}

int posicion(char a,vector<pair<char,int>> b ) {
	for(int i=0; i< b.size(); i++) {
		if(a == b[i].first) {
			return i;
		}
	}

	return -1;
}

void contar(string diet, string desy, string almu) {
	vector<pair<char,int>> dieta;
	vector<pair<char,int>> todo;

	for(int i=0; i<diet.size(); i++) {
		if(!existe(diet[i],dieta)) {
			dieta.push_back(make_pair(diet[i],0));
		}
	}

	for(int i=0; i<desy.size(); i++) {
		int pos = posicion(desy[i],dieta);

		if(pos!= -1) {
			dieta[pos].second++;
		} else {
			todo.push_back(make_pair(desy[i], 1));
		}

	}
	for(int i=0; i<almu.size(); i++) {
		int pos = posicion(almu[i],dieta);

		if(pos!= -1) {
			dieta[pos].second++;
		} else {
			todo.push_back(make_pair(almu[i], 1));
		}

	}

	bool tram = false;
	
	for(int i=0; i<todo.size(); i++) {
		if(count(diet.begin(), diet.end(), todo[i].first)<todo[i].second) {
			tram=true;
			break;
		}
	}

	if(tram) {
		cout<<"CHEATER\n";

	} else {
	string cena;
		for(int i=0; i<dieta.size(); i++) {
			if(dieta[i].second < count(diet.begin(), diet.end(), dieta[i].first)) {
				int veces= count(diet.begin(), diet.end(), dieta[i].first)-dieta[i].second;
				if(veces>0){
					cena.append(veces,dieta[i].first);
				}
				
			}
		}
		sort(cena.begin(), cena.end());

		cout<<cena<<"\n";

	}


	


}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;
	cin.ignore();

	while(n--) {
		string dieta, desy, almu;
		getline(cin, dieta);
		getline(cin, desy);
		getline(cin, almu);
		
		
		contar(dieta, desy, almu);


	}

	return 0;
}