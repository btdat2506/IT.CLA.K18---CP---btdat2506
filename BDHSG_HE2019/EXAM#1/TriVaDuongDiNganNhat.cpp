#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

typedef pair <ll, ll> ii;
 
struct cmp
{
    bool operator() (const ii &L, const ii &R)
    {
        return L.x > R.x;
    }
};
 
ll m, n, d[1100];
vector <ll> edge[1100], cost[1100];
 
void dj()
{
    priority_queue <ii, vector<ii>, cmp> pq;
    pq.push(ii(0, 1));
    while (pq.size() != 0)
    {
        ll du = pq.top().x, u = pq.top().y;
        pq.pop();
        if (du != d[u]) continue;
        for(ll i = 0; i < edge[u].size(); i++)
        {
            ll v1 = edge[u][i];
            if (d[v1] > d[u] + cost[u][i])
            {
                d[v1] = d[u] + cost[u][i];
                pq.push(ii(d[v1], v1));
            }
        }
    }
}
void process()
{
	For(i, 0, 1010) d[i] = INT64_MAX;
	d[1] = 0;
	dj();
	cout << d[n] << endl;
}

void input()
{
	cin >> n >> m;
	For(i, 1, m)
	{
		ll x_temp, y_temp, cost_temp;
		cin >> x_temp >> y_temp >> cost_temp;
		edge[x_temp].push_back(y_temp);
		edge[y_temp].push_back(x_temp);
		cost[x_temp].push_back(cost_temp);
		cost[y_temp].push_back(cost_temp);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();	
}