#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

ll _sieve_size;
bitset<10000010> bs;
vll p;
ll mayor;

void sieve(ll upperbound)                        // range = [0..upperbound]
{
    _sieve_size = upperbound + 1;                    // to include upperbound
    bs.set();                                      // all 1s
    bs[0] = bs[1] = 0;                             // except index 0+1
    for (ll i = 2; i < _sieve_size; ++i)
        if (bs[i])
        {
            // cross out multiples of i starting from i*i
            for (ll j = i*i; j < _sieve_size; j += i) bs[j] = 0;
            p.push_back(i);                              // add prime i to the list
        }
}

int numDiv(ll N)
{
    int ans = 1;
    for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i)
    {
        int power = 0;                               // count the power
        while (N%p[i] == 0)
        {
            N /= p[i];
            ++power;
        }
        ans *= power+1;
                                     // follow the formula
    }
    return (N != 1) ? 2*ans : ans;                 // last factor = N^1
}

vll primeFactors(ll N)                           // pre-condition, N >= 1
{
    vll factors;
    factors.push_back(1);
    for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i)
        while (N%p[i] == 0)                          // found a prime for N
        {
            N /= p[i];                                 // remove it from N
            factors.push_back(p[i]);
        }
    if (N != 1) factors.push_back(N);              // remaining N is a prime
    return factors;
}

int main()
{
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);*/
    ll num;
    vll r;
    string resp = "Y";
    ll total;
    //int totalFactores = 0;

    sieve(10000000);
    cin>>num;
    /*r = primeFactors(num);
    r.push_back(num);
    cout<<"Total: "<<r.size()<<endl;
    for(auto &pf: r){
        printf("> %lld\n",pf);
    }*/

    if(num == 1){
        cout<<"N"<<endl;
    }
    else{
        int ans = 1, power = 0, power1 = 0, power2 = 0, factores = 0;
        for (int i = 0; i < (int)p.size() && p[i]*p[i] <= num; ++i)
        {
            power = 0;                                      // count the power
            while (num % p[i] == 0)
            {
                num /= p[i];
                ++power;
                //cout<<"p[i]: "<<p[i]<<endl;
                //cout<<"num: "<<num<<endl;
            }
            if(!power1){
                power1 = power;
            }
            else if(!power2){
                power2 = power;
            }
            if(power) ++factores;
            //ans *= power + 1;                              // follow the formula
        }
        //totalFactores = (num != 1) ? 2*ans : ans;        // last factor = N^1
        if (num != 1) {
            factores++;
            power = 1;
            if(!power1){
                power1 = power;
            }
            else if(!power2){
                power2 = power;
            }
        }

        /*
        cout<<"Factores: "<<factores<<endl;
        cout<<"Power1: "<<power1<<endl;
        cout<<"Power2: "<<power2<<endl;
        */

        if((factores == 1 && power % 2 != 0) ||
           (factores == 2 && power1 == 1 && power2 == 1)){
            cout<<"Y"<<endl;
        }
        else{
            cout<<"N"<<endl;
        }
    }

    //return (N != 1) ? 2*ans : ans;
    return 0;
}
