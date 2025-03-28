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
	str3 = str1[0];//s
	for(int i = 1; i < str1.size(); i++){
		if((str1[i] == 'a' || str1[i] == 'e' || str1[i] == 'i' || str1[i] == 'o' || str1[i] == 'u')){
			v1 = true;
			guarda1 = str1[i];
			str3 = str3 + str1.substr(1, i - 1);//sp
			//cout << "v1->" << guarda1<<"\n";
			break;
		}
		//else{
			//str3 += str1[i];
			//cout << str3 <<"<-s3\n->"<<str1[i]<<"\n";
		//} 
	}
	//cout << str3 <<"<-s3\n";
	//reverse(str2.begin(),str2.end());
	if(!v1){
		str3 = str3 + str1.substr(1) + mergin + str2;
	}
	else{
		v1 = true;
		for(int i = 1; i < str2.size() ; i++){
			if((str2[i] == 'a' || str2[i] == 'e' || str2[i] == 'i' || str2[i] == 'o' || str2[i] == 'u') && v1){
				v1 = false;
				guarda2 = str2[i];
				str3 = str3 + str2.substr(i);
				//cout << "v2->" << guarda2<<"\n";
				break;
			}
			//else{
				//str4 = str2[i] + str4;
				//cout << str4 <<"<-s4\n->"<<str2[i]<<"\n";
			//}
			if(!v1){
				str3 = str3 + str2.substr(i);
			}
		}
		if(v1){
			str3 = str3 + guarda1;
			str3 = str3 + str2;
		}
	}
	
	//cout << str4 <<"<-s4\n";
	//if(v2){
		//res = str3 + guarda2 + str4;
		//cout << "v2\n";
		
	//}
	//else if(v1){
		//res = str3 + guarda1 + str4;
		//cout << "v1\n";
	//}
	//if(!v1 && !v2){
		//res = str3 + mergin + str4;
		//cout << "defecto mergin\n";
	//}
	cout << str3 << "\n";
	return 0;
}
