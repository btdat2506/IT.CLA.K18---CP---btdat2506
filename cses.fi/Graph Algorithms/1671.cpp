#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef tuple<ll, ll> ii;
#define For(i, a, b) for(ll i = a; i <= b; i++)

const ll N = 100010;
ll n, m, d[N];
vector <ii> edge[N];

struct cmp
{
    bool operator () (const ii &L, const ii &R)
    {
        ll l, dl, r, dr;
        tie(dl, l) = L;
        tie(dr, r) = R;
        return dl > dr;
    }
};

void dj()
{
    priority_queue <ii, vector <ii>, cmp> pq;
    For(i, 0, n+2) d[i] = 1e16;
    ll u, du, v, v_cost; d[1] = 0;
    pq.push({0, 1});
    while (!pq.empty())
    {
        tie(du, u) = pq.top();
        pq.pop();
        if (du > d[u]) continue;
        for(ii vc: edge[u])
        {
            tie(v, v_cost) = vc;
            if (d[v] > d[u] + v_cost)
            {
                d[v] = d[u] + v_cost;
                pq.push({d[v], v});
            }
        }
    }
}

void process()
{
    dj();
    For(i, 1, n)
    cout << d[i] << " ";
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