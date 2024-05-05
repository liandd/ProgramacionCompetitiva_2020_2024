#include<bits/stdc++.h>
#define maxn 200010
using namespace std;

int lowbit(int x){
    return x & (-x);
}

int c[maxn], n, m;

void modify(int x, int d){
    while(x <= n){
        c[x] += d;
        x += lowbit(x);
    }
}

int query(int x){
    int ans = 0;
    while(x){
        ans += c[x];
        x -= lowbit(x);
    }
    return ans;
}

int main(){
    int i, j, x, y;
    char op[2];

    cin >> n >> m;

    for(i = 1; i <= n; ++i)
        modify(i, 1);

    for(i = 1; i <= m; ++i){
        cin >> op;
        if(op[0] == '?'){
            cin >> x >> y;
            if(x > y) swap(x, y);
            int flag = 0;
            int sum = query(n) + query(x) - query(y - 1);
            flag |= (sum == n - y + 1 + x);
            sum = query(y) - query(x - 1);
            flag |= (sum == y - x + 1);
            if(flag)
                cout << "possible" << endl;
            else
                cout << "impossible" << endl;
        }
        else if(op[0] == '+'){
            cin >> x;
            modify(x, 1);
        }
        else{
            cin >> x;
            modify(x, -1);
        }
    }

    return 0;
}

