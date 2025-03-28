#include <bits/stdc++.h>

using namespace std;

int mcd1(int a, int b) {
	while (b != 0) {
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int mcd2(int a, int b) {
	if(b == 0) return a;
	return mcd2(b, a%b);
}



int main() {

	int a=0, b=0, c=0;

	while(cin>>a>>b>>c) {
		bool tPit=false;
		bool tPitP=false;

		if(pow(a,2)+pow(b,2)==pow(c,2)) {
			tPit=true;
		} else if(pow(c,2)+pow(a,2)==pow(b,2)) {
			tPit=true;
		} else if(pow(c,2)+pow(c,2)==pow(a,2)) {
			tPit=true;
		}

		/*
		if ((a * a + b * b == c * c) ||
		        (a * a + c * c == b * b) ||
		        (b * b + c * c == a * a)) {
			tPit = true;
		}*/

		if(mcd2(mcd2(a,b),c)==1) {
			tPitP=true;
		}

		if(tPit==true  && tPitP==true) {
			cout<<"tripla pitagorica primitiva\n";
		} else if(tPit==true) {
			cout<<"tripla pitagorica\n";
		} else {
			cout<<"tripla\n";
		}
	}

	return 0;
}