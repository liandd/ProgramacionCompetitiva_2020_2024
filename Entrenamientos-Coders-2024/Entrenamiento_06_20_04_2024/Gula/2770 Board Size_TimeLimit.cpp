#include <bits/stdc++.h>

using namespace std;

int main() {

	int x_3d, y_3d, n;
	int x_us,y_us;
	while(scanf("%d%d%d",&x_3d, &y_3d, &n)!=EOF) {
		int por=x_3d*y_3d;
		for(int i=0; i<n; i++) {
			scanf("%d%d",&x_us, &y_us);

			int por2=x_us*y_us;
			if(por==0 || por2==0 || por2>por) {
				cout<<"Nao"<<"\n";
			} else {
				cout<<"Sim"<<"\n";
			}
		}
	}


	return 0;
}
