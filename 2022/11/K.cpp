#include<bits/stdc++.h>
#define maxt  200
#define maxb  100
#ifndef _MSVC_VER
#define	scanf_s	scanf
#endif
int main(){
	int a, b, c, d, bcap, tcap, i, j;
	while (scanf_s("%d %d %d %d", &(a), &(b), &(c), &(d)) == 4){
		for(i = 0; i <= maxt; i++){
			tcap = i * a;
			for(j = 0; j <= maxb; j++){
				bcap = j * b;
				if (tcap - bcap == d && bcap >= c) {
					printf("We need %d truck%s and %d boat%s.\n",
						i, (i == 1) ? "" : "s", j, (j == 1) ? "" : "s");
					break;
				}
			}
			if( j <= maxb){
				break;
			}
		}
		if(i > maxt){
			std::cout<<"No solution.\n";
		}
	}
	return 0;
}
