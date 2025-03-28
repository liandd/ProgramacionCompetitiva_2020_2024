/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int main()
{

long long num,num2,num3;
long long menor=LONG_MAX;

cin>>num>>num2;
vector<long long> arr;

for(int i=0;i<num;i=i+1){
    cin>>num3;
    arr.push_back(num3);
}

if(num<num2){
    sort(arr.begin(),arr.end());
    menor=arr[0];
}else{
for(int i=0;i<num;i=i+1){
    for(int j=0;j<num;j=j+1){
        num2=arr[i]+arr[j];
        if(num2<menor&&i!=j){
            menor=num2;
        }
    }
}
}

cout<<menor;






    return 0;
}