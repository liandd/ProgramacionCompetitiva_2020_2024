#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

ll _sieve_size;
bitset<10000010> bs;
vll p;
ll mayor;

void sieve(ll upperbound)
{
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i < _sieve_size; ++i)
        if (bs[i])
        {
            for (ll j = i*i; j < _sieve_size; j += i) bs[j] = 0;
            p.push_back(i);
        }
}

int numDiv(ll N)
{
    int ans = 1;
    for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i)
    {
        int power = 0;
        while (N%p[i] == 0)
        {
            N /= p[i];
            ++power;
        }
        ans *= power+1;

    }
    return (N != 1) ? 2*ans : ans;
}

int main(){
    ll m;
    sieve(1000000);
    map<int, bool> primos;
    primos[0] = false;
    primos[1] = false;
    primos[2] = true;
    primos[3] = true;
    primos[4] = false;
    primos[5] = true;
    primos[6] = false;
    primos[7] = true;
    primos[8] = false;
    primos[9] = false;


    while(cin>>m){
        ll num = numDiv(m);
        if(num>2 || num ==1){
            cout<<"Nada\n";
        }else{
            bool control = true;
            string aux = to_string(m);
            for(int i=0; i<aux.size() && control; i++){
                int aux2 = aux[i]-'0';
                if(!primos[aux2]) control = false;
            }
            if(control) cout<<"Super\n";
            else cout<<"Primo\n";
        }
    }


return 0;
}
