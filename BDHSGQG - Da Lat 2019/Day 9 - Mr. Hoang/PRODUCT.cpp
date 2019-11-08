#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define MOD 123456789
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, k, ans, a[100010];

void process()
{
    sort(a+1, a+1+n);
    ll l = 1, r = n;
    if (k % 2 != 0)
        ans = a[n],
        k--, r--;
    while (k)
    {
        if ((a[r] % MOD) * (a[r-1] % MOD) > (a[l] % MOD) * (a[l+1] % MOD))
        (ans *= (a[r] % MOD) * (a[r-1] % MOD)) %= MOD;
        else
        (ans *= (a[l] % MOD) * (a[l+1] % MOD)) %= MOD;
        k -= 2;
        l += 2;
        r -= 2;
    }
    cout << ans << "\n";
}

void input()
{
    cin >> n >> k;
    For(i, 1, n) cin >> a[i];
}

int main()
{
    freopen("PRODUCT.INP", "r", stdin);
    freopen("PRODUCT.OUT", "w", stdout);
    ll t;
    cin >> t;
    while (t--)
    {
        ans = 1;
        memset(a, 0, sizeof(a));
        input();
        process();
    }
    return 0;
}
