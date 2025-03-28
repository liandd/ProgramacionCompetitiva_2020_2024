#include <bits/stdc++.h>

using namespace std;

int main()
{

    string cad;
    getline(cin,cad);
    
    cad.erase(unique(cad.begin(), cad.end()),cad.end());
    
    int esp=0, min=0, may=0, mayrep=0, minmayrep=0;
    for(int i=0; i<cad.size(); i++){
        if(cad[i]==' '){
            esp++;
        }
        if(cad[i]>96){
            min++;
        }//minusculas
        if(cad[i]>64 && cad[i]<91){
            may++;
            int aux = i+1;
            if(cad[aux] == ' '){
                aux++;
                if(cad[i]>64 && cad[i]<91 && cad[aux]>64 && cad[aux]<91){
                    minmayrep++;
                }
            }
        }
        if((cad[i]>64 && cad[i]<91) && (cad[i+1]<91 && cad[i+1]>64)){
            mayrep++;
        }
        if((cad[i]>64 && cad[i]<91 && tolower(cad[i])==cad[i+1]) || (cad[i]>96 && cad[i]==tolower(cad[i+1])) ){
            minmayrep++;
        }
    }
    
    cout<<esp+min+(2*may)-mayrep-minmayrep<<"\n";
    
    
    /*Hello
AAAAAAAAAA
Buy Llamas
aaaa    A   a
A AaA
The RUNNERS set new world records */



    return 0;
}
