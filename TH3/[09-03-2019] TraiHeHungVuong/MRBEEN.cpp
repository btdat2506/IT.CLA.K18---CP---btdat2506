#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i < b; i++)

ll c, k, ans = INT64_MIN;

void process()
{
    ll tien = pow(10, k),
    r = c % tien;
    if (r >= tien/2) ans = c + r; else ans = c - r;
    cout << ans << endl;
}

void input()
{
    freopen("MRBEEN.INP", "r", stdin);
    freopen("MRBEEN.OUT", "w", stdout);
    cin >> c >> k;
}

int main()
{
    input();
    if (k == 0) ans = c; else process();
}
