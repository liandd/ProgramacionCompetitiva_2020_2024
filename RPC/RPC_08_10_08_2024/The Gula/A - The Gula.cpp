#include <bits/stdc++.h>

using namespace std;

int main(){
	
	string pal="";
	
	cin>>pal;
	
	transform(pal.begin(), pal.end(), pal.begin(), ::tolower);

	bool ban=true;
	bool ban2=true;	
    
   // alfa
    for (int i = 1; i < pal.length(); i++) {
        if (pal[i-1] < pal[i]) {
            ban = false;
            break;
        }
    }
	
	// inverso alfa
	for (int i = 1; i < pal.length(); i++) {
        if (pal[i-1] > pal[i]) {
            ban2 = false;
            break;
        }
    }

	if(ban || ban2){
		cout<<"yes";
	}else{
		cout<<"no";
	}
	
	cout<<"\n";
	
}