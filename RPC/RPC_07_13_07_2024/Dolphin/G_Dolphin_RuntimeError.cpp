/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string x,y,z,op,i,x1,x2,y1,y2,z1,z2,x3,y3,z3;
    int x4,y4,z4;
    bool help=false, f=false;
    
    cin>>x>>op>>y>>i>>z;
    
    for(int i=0;i<x.size();i++){
        
        if(f==true){
            break;
        }
        
        for(int j=0;j<y.size();j++){
            
            x1=x.substr(0,i);
            y1=y.substr(0,j);
            
            x2=x.substr(i);
            y2=y.substr(j);
            
            x3=y1+x2;
            y3=x1+y2;
            
           x4=stoi(x3);
           y4=stoi(y3);
           z4=stoi(z);
           
           
           if(op=="+"){
               
               if(x4+y4==z4){
                  
                  cout<<x4<<" "<<op<<" "<<y4<<" = "<<z4<<"\n";
                 help=true;
                 f=true;
                 break;
                   
               }
           }
           else{
               if(x4*y4==z4){
                  
                  cout<<x4<<" "<<op<<" "<<y4<<" = "<<z4<<"\n";
                   help=true;
                   f=true;
                   break;
               }
           }
        }
    }
    
    if(help==false){
    for(int i=0;i<x.size();i++){
        if(f==true){
            break;
        }
        for(int j=0;j<z.size();j++){
    
                            x1=x.substr(0,i);
                            z1=z.substr(0,j);
                            
                            x2=x.substr(i);
                            z2=z.substr(j);
                            
                            x3=z1+x2;
                            z3=x1+z2;
                            
                            
                            
                            x4=stoi(x3);
                            y4=stoi(y);
                            z4=stoi(z3);
                            
                            
                           if(op=="+"){ 
                                if(x4+y4==z4){
                                  cout<<x4<<" "<<op<<" "<<y4<<" = "<<z4<<"\n";
                                  help=true;
                                  f=true;
                                  break;
                               }
                                 //92 + 2803 = 669495    6891 * 723 = 4979753
                           }
                           else{
                               if(x4*y4==z4){
                                  cout<<x4<<" "<<op<<" "<<y4<<" = "<<z4<<"\n";
                                  help=true;
                                  f=true;
                                  break;
                               }
                           }
        }
    
}
}


if(help==false){
    for(int i=0;i<y.size();i++){
        if(f==true){
            break;
        }
        for(int j=0;j<z.size();j++){
    
                            y1=y.substr(0,i);
                            z1=z.substr(0,j);
                            
                            y2=y.substr(i);
                            z2=z.substr(j);
                            
                            y3=z1+y2;
                            z3=y1+z2;
                            
                            
                            
                            x4=stoi(x);
                            y4=stoi(y3);
                            z4=stoi(z3);
                            
                            
                           if(op=="+"){ 
                                if(x4+y4==z4){
                                  
                                  cout<<x4<<" "<<op<<" "<<y4<<" = "<<z4<<"\n";
                                  
                                  help=true;
                                  f=true;
                                  break;
                               }
                                 //92 + 2803 = 669495    6891 * 723 = 4979753
                           }
                           else{
                               if(x4*y4==z4){
                                  cout<<x4<<" "<<op<<" "<<y4<<" = "<<z4<<"\n";
                                  help=true;
                                  f=true;
                                  break;
                               }
                           }
        }
    
}
}
    return 0;
}