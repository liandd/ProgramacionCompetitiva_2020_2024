#include <bits/stdc++.h>

using namespace std;

int main()
{

    string cad;
    int z,c=0;
    bool b1=true,b2=true;

    cin>>cad;

    z=cad.size();

    for(int i=1;i<cad.size();i++){

       if(tolower(cad[i-1])<=tolower(cad[i])){

        //cout<<"a ";
       }else{

        b1=false;
       }


       if(tolower(cad[i-1])>=tolower(cad[i])){

        //cout<<cad[z-i-1]<<" "<<cad[z-i]<<endl;
       }
       else{
           b2=false;
       }

    }

    if(b1==false and b2==false){
        cout<<"no\n";
    }
    else{
        cout<<"yes\n";
    }
    /*bekloppt
Ente
Rommee */



    return 0;
}
