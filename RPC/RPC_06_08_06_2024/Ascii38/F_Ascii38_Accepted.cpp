#include<bits/stdc++.h>
using namespace std;

int binarySearch(int a[],int lf, int ri, int element){
	int mid, result = -1;
	while(lf <= ri){
		mid = (lf + ri) >> 1;
		if(a[mid] == element){
			result = mid;
			break;
		}
		else{
			if(element > a[mid]){
				lf = mid + 1;
			}
			else{
				ri = mid - 1;
			}
		}
	}
	if(result == -1)
		result = -lf - 1;
	return result;
}

int main(){
	int n, p;
	scanf("%d %d",&n,&p);
	int a[n + 2];
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	
	sort(a,a+n);
	int tmp = 0;
	tmp = binarySearch(a,0,n-1,p);
	if(tmp >= 0){
		printf("%d\n", a[tmp]);
	}
	else printf("%d\n", a[tmp*(-1)-2]);

	
	
	return 0;
}
