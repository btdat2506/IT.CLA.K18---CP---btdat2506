#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    ll t, n, d;
    cin >> t;
    while(t--)
    {
        cin >> n >> d;
        if (d <= n) cout << "YES" << "\n";
        else
        {
            ll x = sqrt(d);
            if (x + d / (x + 1) <= n)
                cout << "YES" << "\n";
            else
                cout << "NO" << "\n";
        }
    }
}