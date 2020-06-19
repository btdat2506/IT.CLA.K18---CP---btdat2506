#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, k;
string st;

void process()
{
    st = ' ' + st;
    ll j = 1, ans;
    while (st[j] != '1' && j <= n) j++;
    if (j > n)
    {
        cout << ((n <= k) ? 1 : (((n % k == 0) ? (n - 1) / k : n / k)))  << "\n";
        return;
    }
    ans = (j - k - 1) / k;
    if (ans < 0) ans = 0;
    For(i, j + 1, n)
    if (st[i] == '1') 
    {
        if (i - j - 1 - 2*k > 0) 
        ans += (i - j - 1 - 2*k) / k;
        j = i;
    }
    cout << ans << "\n";
}

void input()
{
    cin >> n >> k >> st;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    ll t;
    cin >> t;
    while (t--)
    {
        input();
        process();
    }
}