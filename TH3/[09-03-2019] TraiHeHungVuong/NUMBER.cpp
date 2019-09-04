#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll inp;
vector <ll> Prime;

void Sieve()
{
    ll n = 1000000;
    vector <ll> isPrime (n+10, 0);
    For(i, 0, n) isPrime[i] = 1;
    isPrime[0] = 0, isPrime[1] = 0;
    For(i, 2, sqrt(n))
    for(ll j = i*i; j <= n; j += i) isPrime[j] = 0;
    For(i, 2, n) if (isPrime[i]) Prime.push_back(i);
}


void process()
{
    ll res = 0;
    for(ll x = 0; x < Prime.size() && Prime[x] <= inp; x++)
    {
        ll temp, temp1;
        temp = temp1 = Prime[x];
        while(temp <= inp) temp *= temp1, res++;
    }
    cout << res << endl;
}

void input()
{
    freopen("NUMBER.INP", "r", stdin);
    freopen("NUMBER.OUT", "w", stdout);
    cin >> inp;
}

int main()
{
    input();
    Sieve();
    process();
}
