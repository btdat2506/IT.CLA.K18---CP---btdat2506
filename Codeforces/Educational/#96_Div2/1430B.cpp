#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, k, res, arr[200010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    ll t;
    cin >> t;
    while (t--)
    {
        res = 0;
        cin >> n >> k;
        For(i, 1, n)
        cin >> arr[i];
        sort(arr+1, arr+1+n, greater<ll>());
        For(i, 1, k+1)
        res += arr[i];
        cout << res << "\n";
    }
}