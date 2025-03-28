#include <bits/stdc++.h>

using namespace std;


string h(string pal) {
	reverse(pal.begin(), pal.end());
	for (int i=0; i<pal.size(); i++) {
		if (pal[i]=='b') {
			pal[i]='d';
		} else if (pal[i]=='d') {
			pal[i] = 'b';
		} else if (pal[i]=='p') {
			pal[i]='q';
		} else if (pal[i]=='q') {
			pal[i]='p';
		}
	}
	return pal;
}

string v(string pal) {
	for (int i=0; i<pal.size();i++) {
		if (pal[i]=='b') {
			pal[i]='p';
		} else if (pal[i]=='p') {
			pal[i]='b';
		} else if (pal[i]=='d') {
			pal[i]='q';
		} else if (pal[i]=='q') {
			pal[i]='d';
		}
	}
	return pal;
}


string r(string pal) {
	reverse(pal.begin(), pal.end());
	for (int i=0; i<pal.size(); i++) {
		if (pal[i]=='b') {
			pal[i]='q';
		} else if (pal[i]=='q') {
			pal[i]='b';
		} else if (pal[i]=='p') {
			pal[i]='d';
		} else if (pal[i]=='d') {
			pal[i]='p';
		}
	}
	return pal;
}
int main() {
	string pal="", con="";

	cin>>pal>>con;

	int tam = con.size();
	for (int i=0; i<tam; i++) {
		if (con[i]=='h') {
			pal = h(pal);
		} else if (con[i]=='v') {
			pal = v(pal);
		} else if (con[i]=='r') {
			pal = r(pal);
		}
	}

	cout<<pal<<"\n";
	// cout<<"Con: "<<con<>"\n";
	return 0;
}
