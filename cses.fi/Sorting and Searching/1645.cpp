#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, arr[200010], val[200010], pos[200010];

void process()
{
    ll pos_t = 0;
    For(i, 1, n)
    {
        pos_t = lower_bound(val + 1, val + 1 + pos_t, arr[i]) - val;
        val[pos_t] = arr[i],
        pos[pos_t] = i;
        cout << pos[pos_t - 1] << ' ';
    }
}

void input()
{
    cin >> n;
    For(i, 1, n)
    cin >> arr[i];
}

int main()
{
    //freopen("test.in", "r", stdin);
    //freopen("test.ok", "w", stdout);
    input();
    process();
}