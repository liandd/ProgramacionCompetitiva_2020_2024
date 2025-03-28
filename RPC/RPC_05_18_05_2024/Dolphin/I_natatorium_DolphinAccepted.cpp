/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    unsigned long long l;
    int n;
    bool malaquias=true;
    cin>>l>>n;
    vector<long>v;
    long a,b,x,y;
    
    for(int i=0;i<n;i++){
        
        cin>>a;
        
        if(l%a==0 and malaquias==true){
        	
        	v.push_back(a);
        	b=a;
        	for(int j=0;j<v.size();j++){
        		
        		if(v[j]!=b){
        			
        			if(b*v[j]==l){
        				x=b;
        				y=v[j];
        				malaquias=false;
        				break;
					}
				}
        		
			}
		}
        
    }
    

    
    if(x<y){
        cout<<x<<" "<<y<<"\n";
    }
    else{
        cout<<y<<" "<<x<<"\n";
    }
    

    return 0;
}

