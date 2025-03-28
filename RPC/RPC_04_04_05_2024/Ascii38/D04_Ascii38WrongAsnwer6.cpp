#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define mergin 'o'
int main(){
	fast
	bool v1 = false, v2 = false;
	//map<char,int> vocales ={{'a',1},{'e',1},{'i',1},{'o',1},{'u',1}};
	//char str1[27] = {'0'}, str2[27] = {'0'}, str3[27] = {'0'}, str4[27] = {'0'};
	string str1 = "", str2 = "", str3 = "", str4 = "";
	char guarda1 = '0', guarda2 = '0';
	string res = "";
	cin >> str1 >> str2;
	//scanf("%s%*c",&str1);
	//scanf("%s%*c",&str2);
	//printf("%s - %s",str1,str2);
	for(int i = 0; i < str1.size(); i++){
		if(i > 0 && str1[i] == 97 || str1[i] == 101 || str1[i] == 105 || str1[i] == 111 || str1[i] == 117){
			v1 = true;
			guarda1 = str1[i];
			//cout << "v1->" << guarda1<<"\n";
			break;
		}
		else{
			str3 += str1[i];
			//cout << str3 <<"<-s3\n->"<<str1[i]<<"\n";
		} 
	}
	//cout << str3 <<"<-s3\n";
	reverse(str2.begin(),str2.end());
	for(int i = 0; i < str2.size() ; i++){
		if(str2[i] == 97 || str2[i] == 101 || str2[i] == 105 || str2[i] == 111 || str2[i] == 117 && i > 0){
			v2 = true;
			guarda2 = str2[i];
			//cout << "v2->" << guarda2<<"\n";
			break;
		}
		else{
			str4 = str2[i] + str4;
			//cout << str4 <<"<-s4\n->"<<str2[i]<<"\n";
		}
	}
	//cout << str4 <<"<-s4\n";
	if(v2){
		res = str3 + guarda2 + str4;
		//cout << "v2\n";
		
	}
	else if(v1){
		res = str3 + guarda1 + str4;
		//cout << "v1\n";
	}
	if(!v1 && !v2){
		res = str3 + mergin + str4;
		//cout << "defecto mergin\n";
	}
	cout << res << "\n";
	return 0;
}
