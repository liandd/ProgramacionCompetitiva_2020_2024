#include <bits/stdc++.h>

using namespace std;

int main()
{
    
    int n,op=1, a=0, b=0;
    string cad="",aux;
    char c;
    
    cin>>n;
    
    for(int i =0;i < n;i++){
        
          cin>>c;
          cad=cad+c;
          if(i > 0 ){
              if( cad[i-1] == '(' && cad[i] == ')'){
                  aux = aux + "1";
              }else if ( cad[i-1] == ')' && cad[i] == '(' ){
                  aux = aux + "*";
              }else if (cad[i-1] == ')' && cad[i] == ')'){
                  aux = aux + "+1";
              }
          }
          
    }
    
    for(int i =0; i < aux.size();i++){
        if(i >0 && aux[i-1] == '*' ){
            op = op  * 1;
        }else if(i >0 && aux[i-1] == '+'){
            op = op + 1;
        }
        }    
        
    cout<<op+1<<"\n";
        
    return 0;
        
}

    


