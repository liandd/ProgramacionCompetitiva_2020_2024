#include <bits/stdc++.h>
using namespace std;

void imp(string pal){
  set<char> m;
    for(int i = 0; i < pal.size(); i++){
        if (pal[i] != ' ') {
            m.insert(pal[i]);
        }
    }
    
    char inicio = '\0';
    char fin = '\0';
    
    for(char i : m) {
        if (inicio == '\0') {
            inicio = i;
            fin = i;
        } else if (static_cast<int>(i) == static_cast<int>(fin) + 1) {
            fin = i;
        } else {
            cout << inicio << ":" << fin << ", ";
            inicio = i;
            fin = i;
        }
    }

    if (inicio != '\0') {
        cout << inicio << ":" << fin << "\n";
    }  
}
int main() {
    string pal;
    
        
        while(getline(cin, pal)){
            if(pal == " "){
                cout<<"\n";
            }else{
                imp(pal);
            }
        }
    

    return 0;
}