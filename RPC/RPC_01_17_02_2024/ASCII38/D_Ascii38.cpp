#include<bits/stdc++.h>

using namespace std;

struct nucleotidos{
    int a;
    int t;
    int g;
    int c;
};

typedef pair<char, int> ci;

bool cmp(ci a, ci b){
    if(a.second > b.second) return true;
    else if(a.second == b.second){
        if (a.first=='A') return true;
        else if(a.first=='T')
            if(b.first!='A') return true;
        else if(a.first=='G')
            if(b.first!='A' && b.first!='T') return true;
        else return false;
    }else return false;
    return false;
}

int main(){
    int n, s, d, ca=0,ct=0,cc=0,cg=0;
    string cadena;
    getline(cin, cadena);
    scanf("%d", &n);
    vector<nucleotidos>repeticiones(cadena.size(),nucleotidos{0,0,0,0});
    for(int i=0; i<cadena.size(); i++){
        if(cadena[i]=='A'){
            ca++;
        }else if(cadena[i]=='T'){
            ct++;
        }else if(cadena[i]=='G'){
            cg++;
        }else{
            cc++;
        }
        repeticiones[i].a = ca;
        repeticiones[i].t = ct;
        repeticiones[i].g = cg;
        repeticiones[i].c = cc;
    }
    for(int i=0; i<cadena.size(); i++){
        cout<<"i: "<<i<<endl;
        cout<<"\tA: "<<repeticiones[i].a<<" T: "<<repeticiones[i].t<<" G: "<<repeticiones[i].g<<" C: "<<repeticiones[i].c<<endl;
    }
    while(n--){
        scanf("%d %d", &s, &d);
        s--;
        d--;
        vector<ci> letras(4);
        letras[0] = ci{'A', 0};
        letras[1] = ci{'T', 0};
        letras[2] = ci{'G', 0};
        letras[3] = ci{'C', 0};
        letras[0].second = repeticiones[d].a - repeticiones[s].a;
        if(cadena[s]=='A') letras[0].second++;
        letras[1].second = repeticiones[d].t - repeticiones[s].t;
        if(cadena[s]=='T') letras[1].second++;
        letras[2].second = repeticiones[d].g - repeticiones[s].g;
        if(cadena[s]=='G') letras[2].second++;
        letras[3].second = repeticiones[d].c - repeticiones[s].c;
        if(cadena[s]=='C') letras[3].second++;
        sort(letras.begin(), letras.end(), cmp);
        for(int i=0; i<4; i++) printf("%c", letras[i].first);
        printf("\n");
    }



return 0;
}
