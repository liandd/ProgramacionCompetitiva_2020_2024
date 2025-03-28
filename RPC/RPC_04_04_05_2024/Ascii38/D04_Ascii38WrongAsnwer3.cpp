#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define mergin 'o'
int main(){
	fast
	bool v1 = true;
	string str1 = "", str2 = "", str3 = "";
	char guarda1 = '0';
	cin >> str1 >> str2;
	str3 = str1[0];
	for(int i = 1; i < str1.size(); i++){
		if((str1[i] == 'a' || str1[i] == 'e' || str1[i] == 'i' || str1[i] == 'o' || str1[i] == 'u')){
			str3 = str3 + str1.substr(1, i - 1);
			guarda1 = str1[i];
			v1 = false;
			break;
		}
	}
	if(v1){
		str3 = str3 + str1.substr(1) + mergin + str2;
	}
	else{
		v1 = false;
		for(int i = 1; i < str2.size() ; i++){
			if((str2[i] == 'a' || str2[i] == 'e' || str2[i] == 'i' || str2[i] == 'o' || str2[i] == 'u') && !v1){
				str3 = str3 + str2.substr(i);
				v1 = true;
				break;
			}
			if(v1){
				str3 = str3 + str2.substr(i);
			}
		}
		if(!v1){
			str3 = str3 + guarda1 + str2;
		}
	}
	cout << str3 << "\n";
	return 0;
}
