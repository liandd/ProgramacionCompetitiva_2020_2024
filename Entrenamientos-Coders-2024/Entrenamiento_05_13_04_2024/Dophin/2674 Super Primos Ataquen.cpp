/**************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

***************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
   int n,d,v=true;//numero entero que queremos saber si es primo
   
while(cin>>n){

	bool primo=true;
        if (n == 2) {
            primo= true;
        } else if (n == 1 || n < 0 || n % 2 == 0) {
            primo = false;
        } else {
            int k = 3;
            while (k <= sqrt(n)) {
                if (n % k == 0) {
                    primo = false;
                }
                k += 2;
            }
        }
	if(primo == true){
	    
	    while(n>0){
	       

	     d=n%10;
	     n=n/10;
	     
	     
	     if(d==0 or d==1 or d==4 or d==6 or d==8 or d==9){
	         v=false;
			 break;
	     }
	        
	    }
	    if(v==false){
	        cout<<"Primo\n";
	    }
	    else{
	        cout<<"Super\n";
	    }
	}
	else{
	    cout<<"Nada\n";
	}
	
v=true;	
	
}	
	return 0;
}