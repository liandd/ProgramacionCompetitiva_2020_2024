#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    int c=0;
    while(cin>>str){
        if(c>0){
            cout<<"\n";
        }

        int n1=0, n2=0, n3=0, n4=0;
        n1=stoi(str.substr(str.size()-1,1));
        n2=stoi(str.substr(str.size()-2,2));
        n3=stoi(str.substr(str.size()-3,3));
        n4=stoi(str.substr(str.size()-4,4));

        int s=0;
        for(int i=0; i<str.size(); i++){
            string str2(1,str[i]);
            s+=stoi(str2);
        }

        int sp=0, sip=0;
        for(int i=0; i<str.size(); i++){
            string str2(1,str[i]);
            if(i%2==0){
                sp+=stoi(str2);
            }else{
                sip+=stoi(str2);
            }
        }
        int co=abs(sp-sip);

        if((n2%4==0 && n3%100!=0) || n4%400==0){
            cout<<"This is leap year.\n";
            if(s%3==0 && n1%5==0){
                cout<<"This is huluculu festival year.\n";
            }
            if(co%11==0 && n1%5==0){
                cout<<"This is bulukulu festival year.\n";
            }
        }else{
            if(s%3==0 && n1%5==0){
                cout<<"This is huluculu festival year.\n";
            }else{
                cout<<"This is an ordinary year.\n";
            }
        }
        c++;
    }
    return 0;
}
