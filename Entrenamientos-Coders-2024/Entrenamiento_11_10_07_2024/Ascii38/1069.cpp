#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
int main() {

fast
string str;
int n=0;
cin>>n;
while (n--) {
int c=0;
cin>>str;
bool f = true;
vector<char> p;
for (int i = 0; i < str.size(); i++) {
if (str[i] == '<') {
p.push_back(str[i]);
} else if (str[i] == '>') {
if (p.empty() || p.back() != '<') {
f = false;
} else {
p.pop_back();
c++;
}
}
        }

        cout<<c<<"\n";
    }

}
//>><<>>>>>><<>>>><
