/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{

    string p1,p2,v1="",v2="",s1="",s2="",res;

    cin>>p1>>p2;
    s1=p1[0];
    s2=p2[p2.size()-1];

    for(int i=1; i<p1.size(); i++)
    {
        /* adcdefun ufhgfrgj*/
        if(p1[i]=='a' or p1[i]=='e' or p1[i]=='i' or p1[i]=='o' or p1[i]=='u' )
        {
            v1=p1[i];
            break;
        }
        s1=s1+p1[i];
    }
    for(int i=p2.size()-2; i>=0; i--)
    {
        if(p2[i]=='a' or p2[i]=='e' or p2[i]=='i' or p2[i]=='o' or p2[i]=='u' )
        {
            s2=p2.substr(i+1,p2.size()-i);
            v2=p2[i];
            break;
        }
        else if(i==0)
        {
            s2=p2;
        }
    }
    if(v2!="")
    {
        res=s1+v2+s2;
        cout<<res<<"\n";
    }
    else if(v1!="")
    {
        res=s1+v1+s2;
        cout<<res<<"\n";
    }
    else
    {
        res=s1+"o"+s2;
        cout<<res<<"\n";
    }
    return 0;
}

