/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;


struct p {
    int con;
    int prio;
    char l;
};
bool cmp (p a, p b){
    if(a.con< b.con){
        return true;
    }else if(a.con< b.con){
        return false;
    }else{
        if(a.prio < b.prio){
           return true;
        }else{
            false;
        }
    }
    return false;
}

int main()
{
    string cad,c,res;
    int n, a,b,A,T,G,C;
    vector<p>v(4);
    
    cin>>cad>>n;
    
    while(n--){
        cin>>a>>b;
        
        c=cad.substr(a-1,b-(a-1));
        
 
        
        for(int i=0;i<c.size();i++){
            
            if(c[i]=='A'){
                A++;
            }
            
            if(c[i]=='T'){
                T++;
            }
            
            if(c[i]=='G'){
                G++;
            }
            
            if(c[i]=='C'){
                C++;
            }
        }
        
        v[0].con=A;
        v[0].l = 'A';
        v[0].prio=4;
        v[1].con=T;
        v[1].l = 'T';
        v[1].prio=3;
        v[2].con=G;
        v[2].l='G';
        v[2].prio=2;
        v[3].con=C;
        v[3].l='C';
        v[3].prio=1;
        
        sort(v.rbegin(),v.rend(),cmp);
        
        cout<<v[0].l<<v[1].l<<v[2].l<<v[3].l<<"\n";
        
        
        A=0,T=0,G=0,C=0;
        
        
        
    }

    return 0;
}

