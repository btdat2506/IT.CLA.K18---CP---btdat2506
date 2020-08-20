#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, x, sum, ans, a[200010];

void process()
{
    ll j = 1;
    For(i, 1, n)
    {
        sum += a[i];
        //cout << a[i] << ' ' << sum << "\n";
        while (sum > x)
            sum -= a[j++];
        if (sum == x)
            ans++,
            sum -= a[j++];
    }
    cout << ans << "\n";
}

void input()
{
    cin >> n >> x;
    For(i, 1, n)
    cin >> a[i];
}

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    input();
    process();
}