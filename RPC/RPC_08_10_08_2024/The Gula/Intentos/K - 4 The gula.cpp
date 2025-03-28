#include <bits/stdc++.h>
using namespace std;

string rr(string s) {
    string result;
    set<char> letra;

    for (char c : s) {
        if (isupper(c)) {
            char a = tolower(c);
            if (letra.find(a) == letra.end()) {
                result += c;
                letra.insert(a);
            }
        }
    }

    return result;
}

string rs(string s) {
    string result;
    set<char> letra;  
    for (char c : s) {
        char a = tolower(c);  
        if (letra.find(a) == letra.end()) {  
            result += a;  
            letra.insert(a); 
        }
    }
    return result;
}
int main() {
	string ora="",aux="";

	getline(cin,ora);
	
	aux=ora;
	
	//Mayus
	ora.erase(remove(ora.begin(), ora.end(), ' '), ora.end());
	ora=rr(ora);
	cout<<ora<<"\n";
	
	//A-Z
	transform(aux.begin(), aux.end(), aux.begin(), ::tolower);
	aux=rs(aux);
	cout<<aux<<"\n";
	
	//Sumar
	int tamOra= ora.size();
	int tamAux= aux.size();
	
	cout<<tamAux<<" AUX\n";
	cout<<tamOra<<" ORA\n";
	cout<<tamOra+tamAux<<"\n";


	return 0;
}