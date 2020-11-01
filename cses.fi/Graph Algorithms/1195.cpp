#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef tuple<ll, ll> ii;
typedef tuple<ll, bool, ll> iii;
#define INF 1e17
#define For(i, a, b) for(ll i = a; i <= b; i++)

const ll N = 100010;
ll n, m, d[N][3];
vector <ii> edge[N];


void dj()
{
    priority_queue <iii, vector<iii>, greater<iii> > pq;
    ll du, max_cost, u, v, cost_v;
    bool state;
    For(i, 1, n) d[i][0] = d[i][1] = INF;
    pq.push({0, 0, 1}); d[1][0] = 0;
    while (!pq.empty())
    {
        tie(du, state, u) = pq.top();
        pq.pop();
        if (du > d[u][state]) continue;
        for(ii t: edge[u])
        {
            tie(v, cost_v) = t;
            if (!state)
            {
                if (d[v][1] > d[u][0] + cost_v/2)
                {
                    d[v][1] = d[u][0] + cost_v/2;
                    pq.push({d[v][1], 1, v});
                }
                if (d[v][0] > d[u][0] + cost_v)
                {
                    d[v][0] = d[u][0] + cost_v;
                    pq.push({d[v][0], 0, v});
                }
            }
            else
            {
                if (d[v][1] > d[u][1] + cost_v)
                {
                    d[v][1] = d[u][1] + cost_v;
                    pq.push({d[v][1], 1, v});
                }
            }
            
        }
    }
}

void process()
{
    dj();
    cout << d[n][1] << "\n";
}

void input()
{
    ll u, v, c;
    cin >> n >> m;
    For(i, 1, m)
    {
        cin >> u >> v >> c;
        edge[u].push_back({v, c});
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    /* freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout); */
    input();
    process();
}