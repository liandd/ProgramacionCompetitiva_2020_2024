#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<char>p;
    string n;


    while(cin>>n){
        stack<char>p;
        for(int i=0;i<n.size();i++){

            if(n[i]=='('){

                p.push(n[i]);
            }

            else if(n[i]==')'){


                if(!p.empty()&& p.top()=='('){

                       p.pop();
                }
                 else{
                        p.push(n[i]);

                }

            }
        }

        if(p.empty()){
            cout<<"correct\n";
        }
        else{
            cout<<"incorrect\n";
            }


    }


    return 0;
}
