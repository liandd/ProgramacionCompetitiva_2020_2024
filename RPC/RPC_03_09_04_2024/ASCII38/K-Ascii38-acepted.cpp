#include<bits/stdc++.h>
using namespace std;

int main(){
	map<char, int> vocales = {{'A',1},{'E',1},{'I',1},{'O',1},{'U',1},{'Y',1}};
	int n = 0, cont = 0;
	bool flag = true;
	string s;
	scanf("%d", &n);
	vector<string> pal(n);
    for (int i = 0; i < n; i++){
        string s;
        cin>>s;
        if(s.size() > 3) s = s.substr(0, 3);
        pal[i] = s;
    }
    for (int i = 0; i < n; i++){
      if(i==n-1){
        cont++;
        break;
      }
      if(i==n-2){
        cont += 2;
        i++;
        break;
      }
      if(vocales[pal[i][0]] == 1
         || vocales[pal[(i+1)%pal.size()][0]] == 1
         || vocales[pal[(i+2)%pal.size()][0]] == 1) {
        cont++;
      }
      else{
        if(vocales[pal[(i+1)%pal.size()][1]] == 1 ){
          cont += 2;
          pal[(i+1)%pal.size()] = pal[(i+1)%pal.size()].substr(1, pal[(i+1)%pal.size()].size());
        }
        else if(vocales[pal[i][1]] == 1 ){
            cont += 2;
          }
        else if(vocales[pal[i][2]] == 1 ){
            cont += 3;
        }
        else{
            printf("*\n");
            flag = 0;
            return 0;
		}
      }
    }
  if(flag==1) printf("%d\n", cont);
  return 0;
  }

