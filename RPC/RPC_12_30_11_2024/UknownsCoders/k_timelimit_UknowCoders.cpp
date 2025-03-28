#include <bits/stdc++.h>
using namespace std;

string trans_palabra(char t, string s){
	
	string s2 = "";
	switch(t){
    case 'h':
        s2="";
     for(int j=0;j<s.size();j=j+1){

        if(s.at((s.size()-1)-j)=='b'){
            s2=s2+'d';

        }else if(s.at((s.size()-1)-j)=='d'){
          s2=s2+'b';

        }else if(s.at((s.size()-1)-j)=='p'){
         s2=s2+'q';

        }else{
         s2=s2+'p';

        }

     }
     break;
    case 'v':
        s2="";
        for(int w=0;w<s.size();w=w+1){
           if(s.at(w)=='b'){
            s2=s2+'p';
           }else if(s.at(w)=='d'){
           s2=s2+'q';
           }else if(s.at(w)=='p'){
           s2=s2+'b';
           }else{
           s2=s2+'d';
           }
        }
        break;

    case'r':

        s2="";
        for(int l=0;l<s.size();l=l+1){

           if(s.at((s.size()-1)-l)=='b'){
            s2=s2+'q';

        }else if(s.at((s.size()-1)-l)=='d'){
          s2=s2+'p';

        }else if(s.at((s.size()-1)-l)=='p'){
         s2=s2+'d';
        }else{
         s2=s2+'b';
        }
        }
        break;
      }
	
	return s2;
}





int main(){
	
	string s = "", t= "";
	
	
	cin>>s>>t;
	
	vector<int>cont(3);
	
	fill(cont.begin(), cont.end(),0);
	
	for(int i=0; i<t.size(); i++){
		
		if(t.at(i) == 'h'){
			
			cont[0]++;
			
		}else if(t.at(i) == 'v'){
			
			cont[1]++;
		}else{
			
			cont[2]++;
		}
		
	}
	
	for(int i=0; i<3; i++){
		
		if(cont[i]%2!=0){
			char letter;
			
			if(i==0){
				letter='h';
			}
			else if(i==1){
				letter='v';
			}
			else{
				letter='r';
			}
			
			
			s=trans_palabra(letter,s);
			
		}
	}
	
	cout<<s<<"\n";
	
	return 0;
}
