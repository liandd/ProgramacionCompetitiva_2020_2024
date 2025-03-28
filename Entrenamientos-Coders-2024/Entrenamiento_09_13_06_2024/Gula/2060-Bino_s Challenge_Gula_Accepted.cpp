#include <bits/stdc++.h>

using namespace std;
int main(){
	
	int n;
	int x;
	
	int cont2=0, cont3=0, cont4=0, cont5=0;
	
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",&x);
		
		if(x%2==0){
			cont2++;
		}
		if(x%3==0){
			cont3++;
		}
		if(x%4==0){
			cont4++;
		}
		if(x%5==0){
			cont5++;
		}
	}
	
	cout<<cont2<<" Multiplo(s) de 2\n";
	cout<<cont3<<" Multiplo(s) de 3\n";
	cout<<cont4<<" Multiplo(s) de 4\n";
	cout<<cont5<<" Multiplo(s) de 5\n";
	
	
	
	
	return 0;
}