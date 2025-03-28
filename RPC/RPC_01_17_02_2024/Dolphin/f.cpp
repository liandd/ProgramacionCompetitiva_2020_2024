/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;


int main()
{
    
    int v[10];
    string num1,num2;
    char p;
    int c=0;
    
    v[0]=0;
    v[1]=0;
    v[2]=0;
    v[3]=0;
    v[4]=0;
    v[5]=0;
    v[6]=0;
    v[7]=0;
    v[8]=0;
    v[9]=0;
    
    cin>>num1>>num2;
 
while(num1.size()<=num2.size()){ 
    
    for(int i=0;i<num1.size();i++){
        
        if(num1[i]=='0'){
            v[0]++;
        }
        if(num1[i]=='1'){
            v[1]++;
        }
        if(num1[i]=='2'){
            v[2]++;
        }
        if(num1[i]=='3'){
            v[3]++;
        }
        if(num1[i]=='4'){
            v[4]++;
        }
        if(num1[i]=='5'){
            v[5]++;
        }
        if(num1[i]=='6'){
            v[6]++;
        }
        if(num1[i]=='7'){
            v[7]++;
        }
        if(num1[i]=='8'){
            v[8]++;
        }
        if(num1[i]=='9'){
            v[9]++;
        }
    }
    
    num1="";
    
    if(v[0]!=0){
        p =  (v[0]+'0');
        num1=num1+p;
        num1=num1+'0';
       
    }
    if(v[1]!=0){
        p =  (v[1]+'0');
        num1=num1+p;
        num1=num1+'1'; 
       
    }
    if(v[2]!=0){
        p =  (v[2]+'0');
        num1=num1+p;
        num1=num1+'2';
       
    }
    if(v[3]!=0){
          p =  (v[3]+'0');
          num1=num1+p;
        num1=num1+'3';
       
    }
    if(v[4]!=0){
        p =  (v[4]+'0');
        num1=num1+p;
        num1=num1+'4';
       
    }
    if(v[5]!=0){
        p =  (v[5]+'0');
        num1=num1+p;
        num1=num1+'5';
       
    }
    if(v[6]!=0){
        p =  (v[6]+'0');
        num1=num1+p;
        num1=num1+'6';
       
    }
    if(v[7]!=0){
        p =  (v[7]+'0');
        num1=num1+p;
        num1=num1+'7';
       
    }
    if(v[8]!=0){
        p =  (v[8]+'0');
        num1=num1+p;
        num1=num1+'8';
       
    }
    if(v[9]!=0){
        p =  (v[9]+'0');
        num1=num1+p;
        num1=num1+'9';
       
    }
    
    c++;
    
    v[0]=0;
    v[1]=0;
    v[2]=0;
    v[3]=0;
    v[4]=0;
    v[5]=0;
    v[6]=0;
    v[7]=0;
    v[8]=0;
    v[9]=0;

    cout<<num1<<"\n";
    
    if(num1==num2){
        break;
    }
}
cout<<c;
    return 0;
}

