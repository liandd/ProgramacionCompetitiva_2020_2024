#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<int> prueba;
    vector<int> sorted;
    vector<int> copy;
    int t=0,num=0;
    string str;
    cin>>t;

    for(int i=0;i<t;i=i+1){
        cin>>str;
        if(str=="PUSH"){
            cin>>num;
            prueba.push(num);
            sorted.push_back(num);
        }else if(str=="POP"){
            if(prueba.empty()){
                cout<<"EMPTY\n";
            }else{
                prueba.pop();
                sorted.pop_back();
            }

        }else if(str=="MIN"){
            if(prueba.empty()){
                cout<<"EMPTY\n";
            }else{
                copy=sorted;
                sort(copy.begin(),copy.end());
                cout<<*min_element(copy.begin(),copy.end())<<"\n";
            }

        }
    }
    return 0;
}
