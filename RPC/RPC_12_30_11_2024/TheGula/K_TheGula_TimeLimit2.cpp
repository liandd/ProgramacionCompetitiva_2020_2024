#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);  
	cin.tie(nullptr);
	string pal="",condicion="", con="";

	cin>>pal>>condicion;
	
	bool nose=false;

	int x=condicion.size();
	for (int i = 0; i < x; i++) {
		int count = 1;
		while (i + 1 < x && condicion[i] == condicion[i + 1]) {
			count++;
			i++;
		}

		if (count % 2 != 0) {
			con += condicion[i];
		}
	}
	int tam = con.size();
	for (int i=0; i<tam; i++) {
		
		if (con[i]=='h') {
			//reverse(pal.begin(), pal.end());
				nose=!nose;
			for (int j=0; j<pal.size(); j++) {
				if (pal[j]=='b') {
					pal[j]='d';
				} else if (pal[j]=='d') {
					pal[j] = 'b';
				} else if (pal[j]=='p') {
					pal[j]='q';
				} else if (pal[j]=='q') {
					pal[j]='p';
				}
			}
		} else if (con[i]=='v') {
			for (int j=0; j<pal.size(); j++) {
				if (pal[j]=='b') {
					pal[j]='p';
				} else if (pal[j]=='p') {
					pal[j]='b';
				} else if (pal[j]=='d') {
					pal[j]='q';
				} else if (pal[j]=='q') {
					pal[j]='d';
				}
			}
		} else if (con[i]=='r') {
			//reverse(pal.begin(), pal.end());
			nose=!nose;
			for (int j=0; j<pal.size(); j++) {
				if (pal[j]=='b') {
					pal[j]='q';
				} else if (pal[j]=='q') {
					pal[j]='b';
				} else if (pal[j]=='p') {
					pal[j]='d';
				} else if (pal[j]=='d') {
					pal[j]='p';
				}
			}
		}
	}
	
	if(nose){
		reverse(pal.begin(), pal.end());
	}

	cout<<pal<<"\n";
	//cout<<"Con: "<<con<<"\n";
	return 0;
}
