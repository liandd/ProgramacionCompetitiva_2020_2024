//en proceso
#include <bits/stdc++.h>

using namespace std;

int mcd(int a, int b) {
    int temporal;//Para no perder b
    while (b != 0) {
        temporal = b;
        b = a % b;
        a = temporal;
    }
    return a;
}

struct p {
    long long x;
    long long y;
};

int main()
{
    long long n;

    cin>>n;
    vector<p>ve(n*2);
    long long v[n];
    long long res=0,val;
    
    for(int i =0; i<n;i++){
        cin>>v[i];
        
        ve[i].x=i+1;
        ve[i].y=i+1;
        

    }
    
    for(int i=n, j=0; i<n*2, j<n;i++,j++){
        
          ve[i].x=j+1;
          ve[i].y=j+2;
        
    }
    
    ve[(n*2)-1].x=1;
    ve[(n*2)-1].y=n;
    
    /*for(int i=0;i<n*2;i++){
    	
    cout<<ve[i].x<<" "<<ve[i].y<<endl;
	}*/
	
	for(int i=0;i<n*2;i++){
		
	  val=(ve[i].y*pow(mcd(ve[i].x,ve[i].y),2));
	  res=(res+val)%1000000007;
	}
    
    cout<<res<<"\n";

    return 0;
}
