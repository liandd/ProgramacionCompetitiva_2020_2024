#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define mergin 'o'
int main(){
	fast
	char aux1;
	bool aux2 = true;
	string str1, str2;
    cin >> str1 >> str2;
	string res = "";
    res += str1[0];
    for (int i = 1; i < str1.size(); ++i) {
        if (str1[i] == 'a' || str1[i] == 'e' || str1[i] == 'i' || str1[i] == 'o' || str1[i] == 'u') {
            res += str1.substr(1, i - 1);
            aux1 = str1[i];
            aux2 = false;
            break;
        }
    }
    if (aux2) {
        res += str1.substr(1);
        res += mergin;
        res += str2;
    }else {
        bool aux = false;
	    for (int i = 1; i < str2.size(); ++i) {
	        if ((str2[i] == 'a' || str2[i] == 'e' || str2[i] == 'i' || str2[i] == 'o' || str2[i] == 'u') && aux == false){
	            res += str2.substr(i);
	            aux = true;
	            break;
	    	}
	        if (aux){
	            res += str2.substr(i);
	        }
	    }
	    if (!aux) {
	        res += aux1;
	        res += str2;
	    }
    }
    cout << res << "\n";
	/*bool v1 = true;
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
			if((str2[i] == 'a' || str2[i] == 'e' || str2[i] == 'i' || str2[i] == 'o' || str2[i] == 'u') && v1==false){
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
	cout << str3 << "\n";*/
	return 0;
}
