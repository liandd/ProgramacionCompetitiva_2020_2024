#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int mirar(string str, char hdmi, int m){
    int maxi2=0;
    for(int i=0; i<str.size(); i++){
        int c=1;
        int h=m;
        if(str[i]==hdmi){
                int j=i+1;
            for(j; j<str.size() && h>0; j++){
                if(str[j]!=hdmi){
                    h--;
                }else{
                    c++;
                }
            }
            while(j<str.size() && str[j]==hdmi){
                c++;
                j++;
            }
            maxi2=max(maxi2, c);
        }
        while(i+1<str.size() && str[i+1]==hdmi && str[i]==hdmi){
            i++;
        }
    }
    return maxi2;
}

int main(){
    fast
    string str;
    cin>>str;

    int m=0;
    cin>>m;

    string str2=str;
    sort(str2.begin(), str2.end());
    str2.erase(unique(str2.begin(), str2.end()), str2.end());

    int maxi=0;
    int f=0;
    for(char i='a'; i<='z'; i++){
        if(str2[f]==i && f<str2.size()){
            maxi=max(maxi, mirar(str, i, m));
            f++;
        }
    }

    cout<<maxi<<"\n";

    return 0;
}
