#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    string word = "";

    int cost = 0;
    int spaces = 0;
    for (char c : s) {
        if (c == ' ') {
            spaces++;
        }
    }
    bool flag = false;
    bool flag2 = false;
    char ultimo = 'a';
    char recocha = 'b';
    bool shiftted = false;
    while(ss >> word){
		unordered_set<char> lowercase_seen;
	    unordered_set<char> uppercase_seen;
	    bool space_seen = false;
	    for (char c : word) {
	        if (c >= 'a' && c <= 'z') {
	        	char sorner = c;
	        	if(flag2){
					if (lowercase_seen.find(c) == lowercase_seen.end() ||(sorner != recocha)) {
						lowercase_seen.insert(c);
						recocha = c;// U
						
	                	cost += 1;
						//cout<<"norepiteminuscula:"<<cost<<"\n";
	            	}
	            	else continue;
				}
	            if (lowercase_seen.find(c) == lowercase_seen.end()) {
	                lowercase_seen.insert(c);
	                cost += 1;
					//cout<<"primeravez:"<<cost<<"\n";
	                flag2 = true;
	                flag = false;
	                recocha = c;
	            }

	        } else if (c >= 'A' && c <= 'Z') {
	        	char actual = c; //R //U //N //N
				if(flag){
					if (uppercase_seen.find(c) == uppercase_seen.end() ||(actual != ultimo)) {
						uppercase_seen.insert(c);
						ultimo = c;// U
						
	                	cost += 1;
						//cout<<"norepitemmayus:"<<cost<<"\n";
	            	}
	            	else continue;
				}
	            if (uppercase_seen.find(c) == uppercase_seen.end()) {
	            		
						uppercase_seen.insert(c);//T
						ultimo = c; // T
						flag = true;
						flag2 = false;
	                	cost += 2;
						//cout<<"primeravezMayus:"<<cost<<"\n";        
	            }
	                
	            
	        } 
	        else if (c == ' '){
	        	cost +=1;
			}
	    } 

	}
    cout << cost+spaces << endl;
    return 0;
}
