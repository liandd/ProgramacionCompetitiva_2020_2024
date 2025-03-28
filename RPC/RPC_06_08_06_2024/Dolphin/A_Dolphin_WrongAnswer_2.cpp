//en proceso
#include <bits/stdc++.h>

using namespace std;


struct p {
    int x;
    int y;
};

int main()
{
    int n;

    cin>>n;
    vector<p>ve(n*2);
    int v[n];
    
    for(int i =0; i<n;i++){
        cin>>v[i];
        
        ve[i].x=i+1;
        ve[i].y=i+1;
        
        cout<<ve[i].x;
    }
    
    for(int i=n; i<n*2;i++){
        

        
    }
    
    
    
    

    return 0;
}
