#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define si(x)	scanf("%d",&x)
struct P{
    double x, y;
};

const double dmax = numeric_limits<double>::max();

void merge(P p[], int lf, int mid, int ri){
    int n1 = mid - lf+1;
    int n2 = ri - mid;
    P L[n1], R[n2];
    for(int i = 0; i<n1; ++i){
        L[i] = p[lf + i];
    }
    for(int j = 0; j<n2; j++){
        R[j] = p[mid+1+j];
    }
    int i = 0, j = 0, k = lf;
    while(i < n1 && j < n2){
        if(L[i].x <= R[j].x){
            p[k] = L[i];
            i++;
        }else{
            p[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        p[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        p[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(P p[], int lf, int ri){
    if(lf < ri){
        int mid = (lf + ri) >> 1;
        mergeSort(p, lf, mid);
        mergeSort(p,mid+1,ri);
        merge(p, lf, mid, ri);
    }
}

double distancia(P p1, P p2){
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

pair<P,P> distanciaMinima(P p[], int n){
    double dmin = dmax;
    int pasada =1;
    mergeSort(p, 0, n-1);
    
    pasada = 2;
    mergeSort(p, 0, n-1);

    P p1, p2;
    for(int i = 0; i<n; ++i){
        for(int j = i+1; j<n; ++j){
            double dist = distancia(p[i],p[j]);
            if(dist < dmin){
                dmin = dist;
                p1 = p[i];
                p2 = p[j];
            }
        }
    }
    return mp(p1,p2);
}

int main(){
   int N;
   while(si(N) && N){
       P p[N];
       for(int i = 0; i<N; i++){
           cin>>p[i].x>>p[i].y;
       }
       pair<P,P> dismin = distanciaMinima(p,N);
       double d = distancia(dismin.F, dismin.S);
       if(d < 10000) 
           cout<<fixed<<setprecision(4)<<d<<"\n";
       else
           cout<<"INFINITY\n";
   }
   return 0;
}
