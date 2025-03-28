#include <bits/stdc++.h>
using namespace std;

int espacios(string s) {
	int can=0;
	bool ban=false;

	for(int i=0; i<s.length(); i++) {
		if(s[i]==' ') {
			if(!ban) {
				can++;
				ban=true;
			}
		} else {
			ban=false;
		}

	}

	return can;
}

int main() {
	string s;
	getline(cin, s);

	int espa = espacios(s);
	int cont=0;
	bool mayus=false, banEs=false;
	char tem=' ';
	
	for(int i=0; i<s.length(); i++) {

		if(islower(s[i])) {

			if(!banEs && tolower(tem)==s[i]) {
				//cont++;
			} else {
				mayus=false;
				cont++;
				//	cout<<cont<<s[i]<<"  Minus\n";
			}

			while (i + 1 < s.size() && s[i + 1] == s[i]) {
				i++;
			}

		} else if(isupper(s[i])) {


			if(toupper(tem)==s[i]) {
				cont++;
				//cout<<cont<<s[i]<<"  Mayus\n";
			} else if(mayus) {
				cont++;
				//cout<<cont<<s[i]<<"  Mayus2\n";
			} else {
				cont+=2;
				//cout<<cont<<s[i]<<"  Mayus3\n";
				mayus=true;
			}


			while (i + 1 < s.size() && s[i + 1] == s[i]) {
				i++;
			}


		} else {
			// cout<<"Esp\n";
		}

		if(s[i]!=' ') {
			tem=s[i];
			banEs=false;
		} else {
			banEs=true;
		}



	}
	//cout<<espa<<"\n";
	cout<<espa+cont<<"\n";
	return 0;
}
