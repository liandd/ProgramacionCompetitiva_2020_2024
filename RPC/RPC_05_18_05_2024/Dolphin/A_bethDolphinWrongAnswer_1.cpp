/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    
    stack<char>pi;
    char m,a=' ';
    int n,c=0;
    
    cin>>n;
      
      
     /* 10
((())(()))*/

      
    for(int i=0;i<n;i++){
        
        cin>>m;
            //cout<<":D"<<c;
        pi.push(m);
        
        if(a=='(' and pi.top()==')'){
            

            c++;
            //cout<<pi.empty();
            if(!pi.empty()){
                pi.pop();
            }
            
           
            
            if(!pi.empty()){
                pi.pop();
            }
            
             
        }
        
        //cout<<pi.top()<<"sirve"<<endl;
        

        
        if(!pi.empty()){
            a=pi.top();
        }
    }
    
    cout<<c<<"\n";

    

    return 0;
}

