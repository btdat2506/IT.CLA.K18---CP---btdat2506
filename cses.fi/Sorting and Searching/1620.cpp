#include <bits/stdc++.h>
 
using namespace std;
 
typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)
 
ll n, t, c[200010];
 
ll calc(ll timer)
{
    ll res = 0;
    For(i, 1, n)
    res += timer / c[i];
    return res;
}
 
ll bSearch(ll l, ll r)
{
    ll mid = (l + r) / 2;
    while (l != mid && r != mid)
    {
        ll res = calc(mid);
        if (res >= t)
            r = mid;
        else
            l = mid;
        mid = (l + r) / 2;
    }
    return r;
}
 
void process()
{
    cout << bSearch(1, 1e18) << "\n";
}
 
void input()
{
    cin >> n >> t;
    For(i, 1, n)
    cin >> c[i];
}
 
int main()
{
    //freopen("test.in", "r", stdin);
    //freopen("test.ok", "w", stdout);
    input();
    process();
}   