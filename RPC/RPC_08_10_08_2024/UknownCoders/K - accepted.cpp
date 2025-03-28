#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    getline(cin, str);

    str.erase(unique(str.begin(), str.end()), str.end());
    int espacio=0;
    for(int i=0; i<str.size(); i++){
        if(str[i]==' '){
            espacio++;
        }
    }

    int low=0;
    for(int i=0; i<str.size(); i++){
        if(str[i]>96){
            low++;
        }
    }

    int up=0;
    int repmpre=0;
    int repp=0;
    for(int i=0; i<str.size(); i++){
        if(str[i]<91 && str[i]>64){
            up++;
            int j=i+1;
            if(str[j]==' '){
                while(str[j]==' '){
                    j++;
                }
                if(str[i]<91 && str[i]>64 && str[j]<91 && str[j]>64){
                    //cout<<str[i]<<str[i+2]<<""<<str[j]<<str[j-1]<<"\n";
                    repp++;
                }
            }
        }
        if((str[i]<91 && str[i]>64) && (str[i+1]<91 && str[i+1]>64)){
            repmpre++;
        }
        if((str[i]<91 && str[i]>64 && tolower(str[i])==str[i+1]) || (str[i]>96 && str[i]==tolower(str[i+1]))){
            repp++;
        }
    }

    //cout<<espacio<<" "<<low<<" "<<up<<repmpre<<" "<<repp<<"\n";

    cout<<espacio+low+(2*up)-repmpre-repp<<"\n";



    return 0;
}
