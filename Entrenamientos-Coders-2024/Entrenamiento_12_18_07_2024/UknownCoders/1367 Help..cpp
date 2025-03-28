#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=0;
    while(cin>>n && n>0){
        string ch[n];
        int t[n];
        string str[n];

        int s=0, p=0;

        for(int i=0; i<n; i++){
            cin>>ch[i];
            cin>>t[i];
            cin>>str[i];
            if(str[i]=="correct"){
                s++;
                p+=t[i];
            }
            /*if(i>0 && str[i]=="correct" && str[i-1]=="incorrect" && ch[i]==ch[i-1]){
                p+=20;
            }*/
        }

        /*int c=0;
        int s[n];
        for(int i=0; i<n; i++){
            s[i]
                c=0;
                for(int j=0; i<n; i++){
                    if(str[j]=="incorrect"){
                        c++;
                    }
                }
            }
            if(i>0 && str[i]=="correct"){
                p+=20;
            }
        }*/
        int c[n];
        for(int i=0; i<n; i++){
            c[i]=0;
        }
        for(int i=0, h=0; i<n;i++){
            if(i<=n-2){
                if(ch[i]==ch[i+1]){
                    if(str[i]=="incorrect"){
                        c[h]++;
                    }
                }else{
                    p=p+(20*c[h]);
                    h++;
                }
            }else{
                if(ch[i]==ch[i-1]){
                    if(str[i]=="correct" /*str[i-1]=="incorrect"*/ && s!=0){
                        p=p+(20*c[h]);
                        h++;
                    }

                }
            }

        }
        cout<<s<<" "<<p<<"\n";
    }

    return 0;
}
