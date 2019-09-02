#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

vector < vector<ll> > cost;
vector <ll> edge[2000];
ll cost_ong[2000], cost_ba[2000], leng[2000], trace[2000], used[2000], n, m, s, t;

void dj(ll pos)
{
    For(i, 0, 1999) leng[i] = INT64_MAX;
    leng[pos] = 0;
    ll sl = 0; while (1)
    {  
        pos = 0;
        For(i, 1, n)
        if (!used[i] && leng[i] < leng[pos]) pos = i;
        if (pos == 0) return;
        used[pos] = 1;
        for(auto x: edge[pos])
        if (used[x] && leng[x] > leng[pos] + cost[pos][x])
            leng[x] = leng[pos] + cost[pos][x], 
            trace[x] = pos;
    }
}

void process()
{
    dj(s);
    For(i, 1, n) cout << leng[i] << ' ';
    //dj(t);
}

void input()
{
    //freopen("NGAU.INP", "r", stdin);
    //freopen("NGAU.OUT", "w", stdout);
    memset(cost_ong, 0, sizeof(cost_ong));
    memset(cost_ba, 0, sizeof(cost_ba));
    memset(trace, 0, sizeof(trace));
    memset(used, 0, sizeof(used));
    cin >> n >> m >> s >> t;
    cost.resize(n*2);
    For(i, 0, n*2-1) cost[i].resize(n*2);
    For(i, 0, n*2-1)
    For(j, 0, n*2-1) cost[i][j] = 0;
    For(i, 1, m) 
    {
        ll a, b, c;
        cin >> a >> b >> c;
        cost[a][b] = c;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
}

int main()
{
    input();
    process();
}