#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, m, x, l, r;

void process()
{
    l = r = x;
    For(i, 1, m)
    {
        ll a, b;
        cin >> a >> b;
        if ((b >= l && a <= l) || (b >= r && a <= r))
        l = min(l, a),
        r = max(r, b);
    }
    cout << r - l + 1 << "\n";
}

void input()
{
    cin >> n >> x >> m;
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