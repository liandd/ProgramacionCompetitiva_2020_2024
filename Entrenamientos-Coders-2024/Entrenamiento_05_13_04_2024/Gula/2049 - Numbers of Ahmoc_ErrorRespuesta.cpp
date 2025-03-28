#include <bits/stdc++.h>

using namespace std;
int main() {
	int cont=0;
	string sc;
	long long f;
	bool ban=false;

	while(cin>>f && f>0) {
		cont++;
		ban=false;
		cin>>sc;
		int x=to_string(f).length(); //para sacar el tamaño de la fir

		for(int i=0; i<=sc.length()-1; i++) {

			string nosirve=sc.substr(i,x);
			long long ayuda=stoll(nosirve);
			if(ayuda==f) {
				ban=true;
				break;
			}
		}
	
		
		cout<<"Instancia"<<" "<<cont<<"\n";
		if(ban) {
			cout<<"verdadeira";
		} else {
			cout<<"falsa";
		}
		cout<<"\n\n";


	}

	return 0;
}