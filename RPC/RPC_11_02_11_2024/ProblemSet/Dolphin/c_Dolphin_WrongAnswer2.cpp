#include<bits/stdc++.h>
using namespace std;

int p(char c){
    switch(c){
        case 'I':
            return 1;
            break;
        case 'V':
            return 5;
            break;
        case 'X':
            return 10;
            break;
        case 'L':
            return 50;
            break;
        case 'C':
            return 100;
            break;
        case 'D':
            return 500;
            break;
        case 'M':
            return 1000;
            break;
    }
    return 0;
}

int main(){
    int n=0;
    cin>>n;
    while(n--){
        string str;
        cin>>str;

        long long int res=0;
        int c=0;

        for(int i=str.size()-1; i>=1; i--){
            char c1=str[i];
            char c2=str[i-1];
            //cout<<p(c1)<<" "<<p(c2)<<"\n";

            if(p(c1)>p(c2)){
                if(i==str.size()-1){
                    res+=(p(c1)-p(c2));
                }else{
                    res-=p(c2);
                }
                //cout<<res<<"\n";
            }else if(p(c1)<p(c2)){
                if(i==str.size()-1){
                    res+=(p(c1)+p(c2));
                }else{
                    res=res+p(c2);
                }

                //cout<<res<<"\n";
            }else if(p(c1)==p(c2)){

                int j=i;
                for(j=i-1; j>=0 && p(str[i])==p(str[j]); j--){
                     if(j+1==str.size()-1){
                    res+=(p(c1)+p(c2));
                }else if(p(str[i+1])>p(str[j]) ){
                        res-=p(str[j]);
                    }else{
                        res+=p(str[j]);
                    }

                    //cout<<res<<"\n";
                }
                /*if(p(str[i]>p(str[j]))){
                    res-=p(str[i]);
                }else{
                    res+=p(str[i]);
                }*/
                i=j+2;
                //cout<<"i ="<<i<<"\n";
                /*res=res-p(c2);

                c++;*/
            }
        }
        if(c==str.size()-1){
            cout<<str.size()*p(str[0])<<"\n";
        }else{
            cout<<res<<"\n";
        }

    }
    return 0;
}
