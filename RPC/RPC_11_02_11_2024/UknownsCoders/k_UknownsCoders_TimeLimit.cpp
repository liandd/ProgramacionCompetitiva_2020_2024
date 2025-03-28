/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int main()
{

 long long num,num2,sum=0,res,i,num3,num4;
    
    cin>>num>>num2;
    
    num4=num-num2;
    
    if(num==(pow(num2,2))){
        cout<<0<<"\n";
    }else{
        while(sum<num){
        
        if((num-sum)>sum){
        sum=sum+num2;
        }else{
            break;
        }
        //cout<<sum<<"\n";
        i=i+1;
        //cout<<i<<"\n";
        
        
    }
    res=num-sum;
    cout <<res<<"\n";
    }
    
    
    
    
    




    return 0;
}