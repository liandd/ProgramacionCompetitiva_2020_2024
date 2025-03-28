#include <bits/stdc++.h>
using namespace std;
int main()
{

 long long num,num2,num3,num4;
    
    cin>>num>>num2;
    
    
    if(num%num2 == 0){
        cout<<0<<"\n";
    }else{
        
        num3 = (num-num2)/2;
        
        num4 = num3%num2;
        
        cout<<num4*2<<"\n";
        
        
    }
    
  

    return 0;
}
