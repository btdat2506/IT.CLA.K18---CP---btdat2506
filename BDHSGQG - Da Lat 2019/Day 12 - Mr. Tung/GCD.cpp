//VZ37 - GCD

#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i < b; i++)

ll n, k, res, a[100010], M[100010][20];

ll calc(ll i, ll j)
{
    ll k = log2(j - i + 1) + 1;
    return __gcd(M[i][k], M[j - (1 << k) + 1][k]);
}

void SparseTable()
{
    For(i, 1, n)
        M[i][0] = a[i];
    for(ll j = 1; 1 << j <= n; j++)
    for(ll i = 1; i + (1 << j) - 1 <= n; i++)
    M[i][j] = __gcd(M[i][j-1], M[i + (1 << (j - 1))][j - 1]);
}

void process()
{
    SparseTable();
    For(i, 1, n-k)
    res = max(res, calc(i, i+k-1));
    cout << res << "\n";
}

void input()
{
    cin >> n >> k;
    For(i, 1, n) cin >> a[i];
}

int main()
{
    freopen("GCD.INP", "r", stdin);
    freopen("GCD.OUT", "w", stdout);
    input();
    process();
}

//cd "/Volumes/Data/IT.CLA.K18 - btdat2506/BDHSGQG - Da Lat 2019/Day 12 - Mr. Tung/"
// && g++ GCD.cpp -o GCD && 
//"/Volumes/Data/IT.CLA.K18 - btdat2506/BDHSGQG - Da Lat 2019/Day 12 - Mr. Tung/"GCD