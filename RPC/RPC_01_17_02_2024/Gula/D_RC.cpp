#include <bits/stdc++.h>

using namespace std;

void contar(int inicio, int final,string adn) {
	int cT=0, cA=0, cC=0,cG=0;
	string rs;
	for(int i=inicio-1; i<final; i++) {
		char letra=adn[i];
		if(letra=='T') {
			cT++;
		} else if(letra=='A') {
			cA++;
		} else if(letra=='C') {
			cC++;
		} else if(letra=='G') {
			cG++;
		}
	}

	cout<<"T: "<<cT<<" A: "<<cA<<" C: "<<cC<<" G: "<<cG<<"\n";
	//ordenar TACG
	if(cT>cA && cT>cC && cT>cG) {
		if(cA>=cC && cA>=cG) {
			if(cC>=cG) {
				rs="TACG";
			} else {
				rs="TAGC";
			}
		} else if(cC>cA && cC>cG) {
			if(cA>cG) {
				rs="TCAG";
			} else {
				rs="TCGA";
			}
		} else if(cG>cA && cG>cC) {
			if(cC>cA) {
				rs="TGCA";
			} else {
				rs="TGAC";
			}
		}
		//aqui ATCG
	} else if(cA>=cT && cA>=cC && cA>=cG) {
		if(cT>=cC && cT>=cG) {
			if(cC>=cG) {
				rs="ATCG";
			} else {
				rs="ATGC";
			}
		} else if(cC>cT && cC>cT) {
			if(cA>cG) {
				rs="ACTG";
			} else {
				rs="ACGT";
			}
		} else if(cG>cT && cG>cC) {
			if(cC>cA) {
				rs="AGCT";
			} else {
				rs="AGTC";
			}
		}
		//CATG
	} else if(cC>cA && cC>cT && cC>=cG) {
		if(cA>=cT && cA>=cG) {
			if(cT>=cG) {
				rs="CATG";
			} else {
				rs="CAGT";
			}
		} else if(cT>cA && cT>=cG) {
			if(cA>=cG) {
				rs="CTAG";
			} else {
				rs="CTGA";
			}
		} else if(cG>cT && cG>cC) {
			if(cT>cA) {
				rs="CGTA";
			} else {
				rs="CGAT";
			}
		}
		//GATC
	} else if(cG>cA && cG>cT && cG>=cC) {
		if(cA>=cT && cA>=cG) {
			if(cT>=cC) {
				rs="GATC";
			} else {
				rs="GACT";
			}
		} else if(cT>cA && cT>=cG) {
			if(cA>=cC) {
				rs="GTAC";
			} else {
				rs="GTCA";
			}
		} else if(cC>cT && cC>cA) {
			if(cT>cA) {
				rs="GCTA";
			} else {
				rs="GCAT";
			}
		}

	}
	cout<<rs<<"\n";

}

int main() {
	string adn="";
	int ini,fin,cicl;
	cin>>adn>>cicl;
	for(int i=0; i<cicl; i++) {
		cin>>ini>>fin;
		contar(ini,fin,adn);
	}


	return 0;
}