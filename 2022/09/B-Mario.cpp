#include <bits/stdc++.h>

using namespace std;

int main(){
    string cadena;
    string morse="";
    getline(cin, cadena);
    bool control=false;
    
    for(int i=0; i<cadena.size(); i++){
        if((cadena[i]>=65 && cadena[i]<=90) || (cadena[i]>=97 && cadena[i]<=122) || (cadena[i]>=48 && cadena[i]<=57)){
            control=true;
            
            if(cadena[i]=='a' || cadena[i]=='A'){
                morse+=".-";
            }else if(cadena[i]=='b' || cadena[i]=='B'){
                morse+="-...";
            }else if(cadena[i]=='c' || cadena[i]=='C'){
                morse+="-.-.";
            }else if(cadena[i]=='d' || cadena[i]=='D'){
                morse+="-..";
            }else if(cadena[i]=='e' || cadena[i]=='E'){
                morse+=".";
            }else if(cadena[i]=='f' || cadena[i]=='F'){
                morse+="..-.";
            }else if(cadena[i]=='g' || cadena[i]=='G'){
                morse+="--.";
            }else if(cadena[i]=='h' || cadena[i]=='H'){
                morse+="....";
            }else if(cadena[i]=='i' || cadena[i]=='I'){
                morse+="..";
            }else if(cadena[i]=='j' || cadena[i]=='J'){
                morse+=".---";
            }else if(cadena[i]=='k' || cadena[i]=='K'){
                morse+="-.-";
            }else if(cadena[i]=='l' || cadena[i]=='L'){
                morse+=".-..";
            }else if(cadena[i]=='m' || cadena[i]=='M'){
                morse+="--";
            }else if(cadena[i]=='n' || cadena[i]=='N'){
                morse+="-.";
            }else if(cadena[i]=='o' || cadena[i]=='O'){
                morse+="---";
            }else if(cadena[i]=='p' || cadena[i]=='P'){
                morse+=".--.";
            }else if(cadena[i]=='q' || cadena[i]=='Q'){
                morse+="--.-";
            }else if(cadena[i]=='r' || cadena[i]=='R'){
                morse+=".-.";
            }else if(cadena[i]=='s' || cadena[i]=='S'){
                morse+="...";
            }else if(cadena[i]=='t' || cadena[i]=='T'){
                morse+="-";
            }else if(cadena[i]=='u' || cadena[i]=='U'){
                morse+="..-";
            }else if(cadena[i]=='v' || cadena[i]=='V'){
                morse+="...-";
            }else if(cadena[i]=='w' || cadena[i]=='W'){
                morse+=".--";
            }else if(cadena[i]=='x' || cadena[i]=='X'){
                morse+="-..-";
            }else if(cadena[i]=='y' || cadena[i]=='Y'){
                morse+="-.--";
            }else if(cadena[i]=='z' || cadena[i]=='Z'){
                morse+="--..";
            }else if(cadena[i]=='0'){
                morse+="-----";
            }else if(cadena[i]=='1'){
                morse+=".----";
            }else if(cadena[i]=='2'){
                morse+="..---";
            }else if(cadena[i]=='3'){
                morse+="...--";
            }else if(cadena[i]=='4'){
                morse+="....-";
            }else if(cadena[i]=='5'){
                morse+=".....";
            }else if(cadena[i]=='6'){
                morse+="-....";
            }else if(cadena[i]=='7'){
                morse+="--...";
            }else if(cadena[i]=='8'){
                morse+="---..";
            }else if(cadena[i]=='9'){
                morse+="----.";
            }
            /*if(i!=cadena.size()-1){
                morse+=" ";
            }*/
        }
    }
    
    if(!control) {
	cout<<"NO\n"; 
	return 0;
	}
	/*
    for(int i=0; i<morse.size() && i<=(morse.size()-1-i); i++){
        if(morse[i]!=morse[morse.size()-1-i]){
            cout<<"NO\n";
            return 0;
        }
    }*/
    
    string morse2;
    
    for(int i=morse.size()-1;i>=0;i--){
    	
    	morse2+=morse[i];
	}
	
	//cout<<morse<<endl<<morse2<<endl;
	
	int comp=morse.compare(morse2);
	if(comp==0){
		
		cout<<"YES\n";
	}else{
		
		cout<<"NO\n";
	}
    
    //cout<<"YES\n";

return 0;
}
