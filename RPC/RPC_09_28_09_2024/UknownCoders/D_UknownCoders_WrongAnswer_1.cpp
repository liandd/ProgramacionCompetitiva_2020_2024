#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int encontrarMaximos(int a[], int x, int y){
    int m=a[x];
    for (int i=x+1; i<y; i++){
        if(a[i]>m){
            m=a[i];
        }
    }
    return m;
}

int encontrarMinimos(int a[], int x, int y){
    int m=a[x];
    for (int i=x+1; i<y; i++){
        if(a[i]<m){
            m=a[i];
        }
    }
    return m;
}

int bs(int A[],int i, int j, int k){
    int m=0; int result=-1;

    while(i<=j){
        m=(i+j)>>1;
        if(A[m]==k){
            result=m;
            break;
        }else{
            if(k>A[m]){
                i=m+1;
            }else{
                j=m-1;
            }
        }
    }
    if(result==-1){
    result=(-1)*i-1;
    }
    return result;
}


int main(){
    fast
    int n=0, m=0;
    cin>>n>>m;

    int ar[n];
    for(int i=0; i<n; i++){
        cin>>ar[i];
    }

    vector<int> h;
    vector<int> h2;
    for(int i=0; i<n; i++){
        if(m*i+1<n){
            h.push_back(encontrarMaximos(ar,m*i,  min(n, m*(i+1)) ));
            h2.push_back(encontrarMinimos(ar,m*i,  min(n, m*(i+1)) ));
        }else{
            break;
        }
    }

    int ma=0;
    for(int i=0; i<h.size(); i++){
        if(h[i]-h2[i]>ma && bs(ar, m*i, min(n, m*(i+1)), h[i]) > bs(ar, m*i, min(n, m*(i+1)), h2[i])){
            ma=h[i]-h2[i];
        }else if(h2[i]-h[i]>ma && bs(ar, m*i, min(n, m*(i+1)), h[i]) < bs(ar, m*i, min(n, m*(i+1)), h2[i])){
            ma=h2[i]-h[i];
        }
    }
    cout<<ma<<"\n";

    return 0;
}
