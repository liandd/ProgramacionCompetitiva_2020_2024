#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,n1;
    string cad;
    char g='z';
    cin>>n>>m;
    string v[n];

    n1=n;
    int mayor=0;
    char cmayor;

    while(n--){

        cin>>v[n];
    }

    for(int i=0;i<m;i++){

       map<char,int> map;

        for(int j=0;j<n1;j++){


        cad=v[j];

        map[cad[i]]++;

           /* if(cad[i]<g){


                g=cad[i];
            }*/

        }

        for(auto k: map){

          //  cout<<k.first<<" "<<k.second<<endl;;

            if(k.second>mayor){

                //cout<<"entro1"<<endl;

                mayor=k.second;
                cmayor=k.first;
                 //cout<<"cmayor 1 vale: "<<cmayor<<endl;
            }
            else if(k.second==mayor){
              //  cout<<"entro2"<<endl;
              //cout<<"cmayor 2 vale: "<<cmayor<<endl;
                if(k.first<=cmayor){
                //    cout<<"entro3"<<endl;
                    cmayor = k.first;
                    mayor  = k.second;
                }
            }


        }
         mayor=0;
         cout<<cmayor;
        cmayor='A';



    }

    cout<<"\n";



    return 0;
}

