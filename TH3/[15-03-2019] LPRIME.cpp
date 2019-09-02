#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll m, n;
vector < vector<ll> > db;
vector <ll> isPrime;

void Sieve()
{
    ll siz = 100000;
    isPrime.resize(siz);
    For(i, 0, siz-1) isPrime[i] = 1;
    isPrime[0] = 0, isPrime[1] = 0;
    For(i, 2, sqrt(siz))
    for(ll j = i*i; j <= siz; j += i) isPrime[j] = 0;
}

void process()
{
    
}

void input()
{
    freopen("LPRIME.INP", "r", stdin);
    freopen("LPRIME.OUT", "w", stdout);
    cin >> m >> n;
    db.resize(m+10);
    For(i, 0, m+9) db[i].resize(n+10);
    For(i, 1, m)
    For(j, 1, n)
    cin >> db[i][j];
}

int main()
{
    input();
    Sieve();
    process();
}