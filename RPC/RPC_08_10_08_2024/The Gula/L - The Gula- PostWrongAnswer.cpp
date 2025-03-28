#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;

	int n = s.length();
	int i=1;

	while((32 * pow(2, i - 1)) < n){
		cout << "long ";	
		i++;
	}
	cout<<"long\n";
/*
	for (i = 1; i < n; i++) {
		if ((32 * pow(2, i - 1)) >= n) {
			break;
		}
	}

	for (int j = 0; j < i; j++) {
		cout << "long ";
	}
	cout << "\b\n";*/
	return 0;
}