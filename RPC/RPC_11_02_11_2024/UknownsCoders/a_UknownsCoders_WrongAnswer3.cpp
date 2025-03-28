#include<bits/stdc++.h>
using namespace std;
int main(){

    unsigned long long n=0,k=0,cont=1,cont2=0,n2=0, n3=0, rest=0, tm=0;
    string s="";

    cin>>n>>k;
    tm=k+1;

     if(n%tm==0){
        cout<<n/(k+1)<<"\n";

        }else{

        for(unsigned long long i=0;i<n;i++){
        n3=n-n2;

        if (cont<=k){
            cont++;
           // cout<<cont<<"\n";
            s=s+"0";
            n2++;

        }else{
          s=s+"1";//1
          cont=1;//0
          n2++;
        }

        if(s.at(i)=='1'){
          cont2=cont2+1;//1,99
        }
         if(n3<=k && s.at(i)=='1'){
            break;
        }

        }

        rest=n-s.length();

       //cout<<s<<"\n";
        //cout<<cont2<<"\n";
        //cout<<rest<<"\n";
        cout<<cont2+rest<<"\n";
    }


        return 0;

    }
