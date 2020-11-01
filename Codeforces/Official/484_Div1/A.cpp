#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

// begin: 15:11:52 Sep/07/2020
// end: 

ll calc(ll l, ll r)
{
    if (l == r) 
        return l;
    ll x = log2(r);
    while (pow(2, x) > r) x--;
    if (pow(2, x) < l) 
        return calc(l - pow(2, x), r - pow(2, x)) + pow(2, x);
    if (pow(2, x + 1) - 1 <= r) 
        return pow(2, x + 1) - 1;
    if (pow(2, x) - 1 <= r) 
        return pow(2, x) - 1;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    ll n;
    cin >> n;
    while (n--)
    {
        ll l, r;
        cin >> l >> r;
        cout << calc(l, r) << "\n";
    }
}