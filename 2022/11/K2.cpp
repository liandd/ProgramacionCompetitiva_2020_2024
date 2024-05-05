#include<bits/stdc++.h>

#define	MAX_TRUCKS	200		
#define	MAX_BOATS	100		
#ifndef _MSVC_VER
#define	scanf_s	scanf
#endif

int main()
{
	int a, b, c, d, nt, nb, bcap, tcap;

	while (scanf_s("%d %d %d %d", &(a), &(b), &(c), &(d)) == 4) {

		for (nt = 0; nt <= MAX_TRUCKS; nt++) {
			tcap = nt * a;

			for (nb = 0; nb <= MAX_BOATS; nb++) {

				bcap = nb *  b;

				if (tcap - bcap == d && bcap >= c) {
					printf("We need %d truck%s and %d boat%s.\n",
						nt, (nt == 1) ? "" : "s", nb, (nb == 1) ? "" : "s");
					break;
				}
			}
			if (nb <= MAX_BOATS) {
				break;
			}
		}

		if (nt > MAX_TRUCKS) {
			printf("No solution.\n");
		}
	}
	return(0);
}
