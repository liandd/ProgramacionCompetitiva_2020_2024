#include <bits/stdc++.h>

using namespace std;

int min(stack <int> &pilita) {

	if(!pilita.empty()) {

		stack<int> aux= pilita;
		int datoMin= aux.top();
		aux.pop();
		while(!aux.empty()) {
			if(datoMin>aux.top()) {
				datoMin=aux.top();
			}
			aux.pop();
		}

		return datoMin;
	}
	return 0;
}


int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	stack <int> pilita;
	int n;
	cin>>n;
	cin.ignore();
	while(n--) {
		int v=0;
		int tam;
		string comand;
		getline(cin, comand);

		if(comand.size()>4) {
			string ss=comand.substr(5);
			v=stoi(ss);

			pilita.push(v);


		} else if(comand=="POP") {
			if(!pilita.empty()) {
				pilita.pop();
			} else {
				cout<<"EMPTY\n";
			}


		} else if(comand=="MIN") {
			if(!pilita.empty()) {
				cout<<min(pilita)<<"\n";
			} else {
				cout<<"EMPTY\n";
			}

		}

	}



	return 0;
}