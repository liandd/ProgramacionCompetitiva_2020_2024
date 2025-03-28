#include<bits/stdc++.h>
using namespace std;
#define myInfinite 2147483647
#define lli long long int

lli inv = 0;
void myMerge(int A[], int lf, int mid, int ri){
	int n1 = mid - lf + 1;
	int n2 = ri - mid;
	int i, j, k;
	int L[n1 + 2], R[n2 + 2];
	for(i = 0; i<n1; i++)
		L[i] = A[lf + i];
		
	for(j = 0; j<n2; j++)
		R[j] = A[mid + 1 +j];
		
	L[n1] = myInfinite;
	R[n2] = myInfinite;
	i = 0;
	j = 0;
	for(k = lf; k <= ri; k++){
		if(L[i] <= R[j]){
			A[k] = L[i];
			i++;
		}
		else{
			A[k] = R[j];
			j++;
			
			inv = inv + n1 - i;
			//printf("%lld\n", inv);
		}
	}
}

void MergeSort(int A[], int lf, int ri){
	if(lf < ri){
		int mid = (lf + ri) >> 1;
		MergeSort(A,lf, mid);
		MergeSort(A,mid+1,ri);
		myMerge(A,lf,mid,ri);
	}
}

int main(){
	int n = 0;
	scanf("%d", &n);
	int A[100005];
	int B[100005];
	
	for(int i=0; i<n; i++)
		scanf("%d", &A[i]);
		
	for(int i=0; i<n; i++)
		scanf("%d", &B[i]);
		
	MergeSort(A,0,n-1);
	MergeSort(B,0,n-1);
	printf("%lld\n", inv);

	return 0;
}
/*
2
1 2
2 1
output 
1
input 2
3
1 3 2
2 1 3
output 2
2
input 3
5
4 5 1 2 3
3 1 4 5 2
8
*/
