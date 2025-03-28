#include<bits/stdc++.h>
#define myinfinite 2147483647
using namespace std;

void mymerge(vector<int> &A, int izq, int mid, int der){
    int n1=mid-izq+1;
    int n2=der-mid;
    int L[n1+2];
    int R[n2+2];
    int i=0, j=0, k=0;

    for(i=0; i<n1; i++){
        L[i]=A[izq+i];
    }
    for(j=0; j<n2; j++){
        R[j]=A[mid+1+j];
    }
    L[n1]=myinfinite;
    R[n2]=myinfinite;
    i=0;
    j=0;

    for(k=izq; k<=der; k++){
        if(L[i]<=R[j]){
            A[k]=L[i];
            i++;
        }else{
            A[k]=R[j];
            j++;
        }
    }
}

void mergeSort(vector<int> &A, int izq, int der){
    int mid=0;
    if(izq<der){
        mid=(izq+der)>>1;
        mergeSort(A, izq, mid);
        mergeSort(A, mid+1, der);
        mymerge(A, izq, mid, der);
    }
}


int main(){
    int t=0, m=0;
    int c=0;
    cin>>t;
    stack<int> pila;
    vector<int> v;
    for(int i=0; i<t; i++){
        string str;
        int n=0;
        cin>>str;
        //cout<<str;
        if(str=="PUSH"){
            cin>>n;
            //cout<<n;
            /*if(n<m){
                m=n;
            }*/

            pila.push(n);
            v.push_back(n);
            //sort(v.begin(), v.end());
            mergeSort(v, 0, v.size()-1);
            m=v[0];


        }else if(str=="MIN"){
            /*int m=pila.top();
            //for(int i=0; i<pila.size(); i++){
            stack<int> pila_copy(pila);
            while(!pila_copy.empty()){
                if(pila_copy.top()<m){
                    m=pila_copy.top();
                }
                pila_copy.pop();

            }*/
            if(pila.empty()){
                cout<<"EMPTY\n";
            }else{
                cout<<m<<"\n";
            }

        }else if(str=="POP"){
            if(pila.empty()){
                cout<<"EMPTY\n";
            }else{
                if(pila.top()==m){
                    c++;
                    m=v[c];
                }
                pila.pop();
            }

        }
    }

    return 0;
}
