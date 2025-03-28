#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

ll _sieve_size;
bitset<10000010> bs;
vll p;

void sieve(ll upperbound)
{
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i < _sieve_size; ++i)
        if (bs[i])
        {
            for (ll j = i * i; j < _sieve_size; j += i) bs[j] = 0;
            p.push_back(i);
        }
}

int num_div(ll t_minus_1, ll n)
{
    int count = 0;
    ll sqrt_t_minus_1 = (ll) sqrt(t_minus_1) + 1;
    for (ll i = 1; i < sqrt_t_minus_1; ++i)
    {
        if (t_minus_1 % i == 0)
        {
            if (i <= n) count += 1;
            if (t_minus_1 / i <= n && i != t_minus_1 / i) count += 1;
        }
    }
    return count;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    sieve(1000000);
    ll q, n, t;
    cin >> q;
    while (q--)
    {
        cin >> n >> t;
        if (t == 1)
            cout << n << "\n";
        else
            cout << num_div(t - 1, n) << "\n";
    }
    return 0;
}
