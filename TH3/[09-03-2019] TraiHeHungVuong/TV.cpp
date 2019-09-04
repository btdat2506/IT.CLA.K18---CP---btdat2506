#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define MOD 1000000000

ll tv, l, a[300][30000], b[30000], ans = 0;

void process(ll i, ll j)
{
    memset(b, 0, sizeof(b));
    merge(a[i]+1, a[i]+l+1, a[j]+1, a[j]+l+1, b);
    //(ans += (b[l-1] % MOD)) %= MOD;
    ans += (b[l-1] % MOD);
}

void input()
{
    memset(a, 0, sizeof(a));
    freopen("TV.INP", "r", stdin);
    freopen("TV.OUT", "w", stdout);
    cin >> tv >> l;
    For(i, 1, tv)
    For(j, 1, l) cin >> a[i][j];
}

int main()
{
    input();
    For(i, 1, tv)
    For(j, i+1, tv)
    process(i, j);
    cout << ans % MOD << endl;
}
