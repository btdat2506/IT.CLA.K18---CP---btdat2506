#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll matchX[1010], matchY[1010], trace[1010], m, n, e;
vector <ll> a[1010];

ll bfs()
{
    queue <ll> q;
    For(i, 1, m)
    if (!matchX[i]) q.push(i);
    memset(trace, 0, sizeof(trace));
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        for(ll i = 0; i < a[u].size(); i++)
        {
            ll v = a[u][i];
            if (trace[v] == 0) 
            {
            	trace[v] = u;
            	if (matchY[v] == 0) return v;
            	else q.push(matchY[v]);
            }
        }
    }
    return 0;
}

void enlarge(ll y)
{
    ll next = 0, x = 0;
    for(; y; y = next)
    {
        x = trace[y],
        next = matchX[x],
        matchX[x] = y,
        matchY[y] = x;
    }
}

void process()
{
    while (ll u = bfs()) enlarge(u);
    ll ans = 0;
    For(i, 1, m)
    if (matchX[i] != 0) ans++;
    cout << ans << endl;
}

void input()
{
    cin >> m >> n >> e;
    For(i, 1, e)
    {
        ll x, y;
        cin >> x >> y;
        a[x].push_back(y);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    input();
    process();
    return 0;
}
