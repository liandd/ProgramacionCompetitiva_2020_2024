#include <bits/stdc++.h>
using namespace std;

int main()
{
    int f,c1,c2;
    char l;
    bool juanes = false,laura=true;
    cin>>f>>c1>>c2;
    
     for(int i = 0; i < f;i++){
         
         for(int j = 0;j <c1;j++){
             
             cin>>l;
             
             if(l=='-'){
                 juanes=true;
             }
         }

         
         for(int k = 0;k <c2;k++){
            
            cin>>l;
            
            if(juanes==true and l=='*'){
                laura=false;
 
            }
         }
          
          juanes=false;
    }
    
    if(laura==false){
        cout<<"N\n";
    }
    else{
        cout<<"Y\n";
    }
    
    return 0;
}

