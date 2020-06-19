#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i < b; i++)

ll l, r;

void process()
{
    ll res = ((r - l + 1) / 9) * 45;
    For(i, 0, (r - l + 1) % 9)
    {
        ll tmp = (l + i) % 9;
        res += (tmp == 0) ? 9 : tmp;
    }
    cout << res << "\n";
}

void input()
{
    cin >> l >> r;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
//    freopen("test.in", "r", stdin);
//    freopen("test.ok", "w", stdout);
    ll t;
    cin >> t;
    while (t--)
    {
        input();
        process();
    }

}