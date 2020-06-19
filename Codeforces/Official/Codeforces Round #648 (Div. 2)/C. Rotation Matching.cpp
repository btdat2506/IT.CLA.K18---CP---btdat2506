#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ii pos[200010];
ll n, ans, a[200010], b[200010], res[200010];

void process()
{
    For(i, 1, n)
    {
        pos[a[i]].first = i;
        pos[b[i]].second = i;
    }
    For(i, 1, n)
    {
        if (pos[i].first < pos[i].second)
        res[n - pos[i].second + pos[i].first]++;
        else
        {
            res[pos[i].first - pos[i].second]++;
        }
    }
    For(i, 0, n)
    ans = max(ans, res[i]);
    cout << ans << "\n";
}

void input()
{
    cin >> n;
    For(i, 1, n)
    cin >> a[i];
    For(i, 1, n)
    cin >> b[i];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    input();
    process();
}