/**************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

***************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,l;
    string fech,num,aux="";
    bool bol=true,v=true;
    
	while(cin>>n>>m){  
		
		
		for(int i=0;i<m;i++){
			
			cin>>fech;
	  
			for(int j=0;j<n;j++){
				
				cin>>l;
				
				if(l==0){
					bol=false;
				}
				
			}
			
			if(bol==true and v==true){
				aux=fech;
				v=false;
			}
			bol=true;
		}
		
		if(aux==""){
			cout<<"Pizza antes de FdI\n";
		}
		else{
			cout<<aux<<"\n";
		}
		
		bol=true;
		aux="";
		v=true;
	}
	/*    
		4 4
	1/6/2016 0 0 1 0
	12/7/2016 1 1 1 0
	5/10/2016 1 1 1 1
	25/12/2016 0 0 0 0*/

    return 0;
}