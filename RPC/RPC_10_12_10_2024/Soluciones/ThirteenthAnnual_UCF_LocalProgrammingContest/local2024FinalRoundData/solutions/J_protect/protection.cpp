
#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

using ll = long long;
using vi = vector<ll>;
using Matrix = vector<vi>;


int my_contained(const string & needle, const string & haystack) {
    if (haystack.size() < needle.size()) return 0;
    for (int i = 0; i <= haystack.size() - needle.size(); i++) {
        int good = 0;
        // cerr << i << endl;
        for (int j = 0; j < needle.size() && i + j < haystack.size(); j++) {
            // cerr << j << endl;
            if (needle[j] != haystack[i+j]) {
                break;
            }
            good++;
        }
        if (good == needle.size()) {
            return 1;
        }
    }
    return 0;
}

Matrix matMult(Matrix & a, Matrix & b, int m) {
    int rr = a.size();
    int cc = b[0].size();
    int n = b.size();
    Matrix res(rr, vi(cc, 0));
    for (int i = 0; i < rr; i++) {
        for (int j = 0; j < cc; j++) {
            for (int k = 0; k < n; k++) {
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= m;
            }
        }
    }
    return res;
}

Matrix ident(int n) {
    Matrix res(n, vi(n, 0));
    for (int i = 0; i < n; i++) res[i][i] = 1;
    return res;
}

Matrix matExpo(Matrix & b, int e, int m) {
    if (e == 0) return ident(b.size());
    if (e == 1) return b;
    Matrix s = matExpo(b, e/2, m);
    s = matMult(s,s,m);
    if (e&1) s = matMult(s,b,m);
    return s;
}

int main() {
    int n;
    string name1;
    string name2;
    cin >> n >> name1 >> name2;
    // Check if the one name is contained in the other
    if (my_contained(name1, name2)) {
        name2 = name1;
    } else if (my_contained(name2, name1)) {
        name1 = name2;
    }

    // Generate all the unique strings
    map<string, int> nm_to_ind;

    nm_to_ind.emplace(name1, 0);
    nm_to_ind.emplace(name2, 0);

    int cnt = 1;
    
    for (int i = 0; i < name1.size(); i++) {
        string sbstr = name1.substr(0,i);
        if (nm_to_ind.find(sbstr) == nm_to_ind.end()) {
            nm_to_ind.emplace(sbstr, cnt++);
        }
    }

    for (int i = 0; i < name2.size(); i++) {
        string sbstr = name2.substr(0,i);
        if (nm_to_ind.find(sbstr) == nm_to_ind.end()) {
            nm_to_ind.emplace(sbstr, cnt++);
        }
    }

    // The matrix
    int N = cnt;
    Matrix mat(N, vi(N));



    for (auto pa : nm_to_ind) {
        if (pa.first == name1 || pa.first == name2) continue;
        for (char c = 'a'; c <= 'z'; c++) {
            string tmp = pa.first + c;
            for (int i = tmp.size(); i >= 0; i--) {
                string tmp2 = tmp.substr(tmp.size()-i,i);
                if (nm_to_ind.find(tmp2) != nm_to_ind.end()) {
                    mat[pa.second][nm_to_ind[tmp2]] += 1;
                    break;
                }   
            }
        }
    }    


    mat[nm_to_ind[name1]][nm_to_ind[name2]] += 26;

    mat = matExpo(mat, n, MOD);

    cout << mat[nm_to_ind[""]][nm_to_ind[name1]] << endl;

    return 0;
}
