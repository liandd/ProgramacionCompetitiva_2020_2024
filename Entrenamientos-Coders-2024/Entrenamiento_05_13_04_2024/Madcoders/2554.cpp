#include<bits/stdc++.h>

using namespace std;


int main(){
    int p, f;
    while(cin>>p>>f){
        string ans = "";
        while(f--){
            //cin.ignore();
            string fecha;
            cin>>fecha;
            bool control = true;
            for(int i = 0; i<p; i++){
                int aux;
                cin>>aux;
                if(!aux) control = false;
            }
            if(control && ans==""){
                ans = fecha;
            }
            cin.ignore();
        }
        if(ans!="") cout<<ans<<endl;
        else cout<<"Pizza antes de FdI\n";


    }


return 0;
}
