#include<bits/stdc++.h>
using namespace std;

int main()
{
    
    string cad;
    int c=0,coor=0,i=0;
    
    cin>>cad;
 
        while(i<cad.size()){
            
                //cout<<i<<endl;
                //cout<<coor<<endl;
            
            
              if(cad[i]=='1' and cad[i+1]=='0'){
               // cout<<"cad1: "<<cad[i]<<" cad1: "<<cad[i+1]<<endl;

                cad[i]='0';
                cad[i+1]='1';
                 c++;
                i=i-1;
                
                if(i<0){
                    i=0;
                }
            }
            else if(cad[i]=='2' and cad[i+1]=='0'){
               // cout<<"cad2: "<<cad[i]<<" cad2: "<<cad[i+1]<<endl;
  
                cad[i]='0';
                cad[i+1]='2';
                 c++;
                i=i-1;
                
                if(i<0){
                    i=0;
                }
            }
            
            else if(cad[i]=='2' and cad[i+1]=='1'){
               // cout<<"cad3: "<<cad[i]<<" cad3: "<<cad[i+1]<<endl;
 
                cad[i]='1';
                cad[i+1]='2';
                c++;
                i=i-1;
                
                if(i<0){
                    i=0;
                }
            }
            else{
                i++;
            }
           
            //cout<<cad<<endl;
           
        }
      
    cout<<c<<"\n";
    
    

    return 0;
}