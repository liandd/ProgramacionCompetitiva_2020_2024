#include <bits/stdc++.h>

using namespace std;

int min(vector<int> &pilita) {
	if(!pilita.empty()) {
		int datoMin=*min_element(pilita.begin(), pilita.end());
		return datoMin;
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	vector<int> pilita;
	int n;
	cin>>n;
	cin.ignore();
	while(n--) {
		int v=0;
		string comand;
		getline(cin, comand);
		if(comand.size()>4) {
			string ss=comand.substr(5);
			v=stoi(ss);
			pilita.push_back(v);
		} else if(comand=="POP") {
			if(!pilita.empty()) {
				pilita.pop_back();
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