#include <bits/stdc++.h>

using namespace std;

clock_t start = clock();

#define ll long long
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define x first
#define y second

typedef pair <ll, ll> ii;

struct Comparison
{
    bool operator() (const ii &L, const ii &R)
    {
        return L.x > R.x;
    }
};

ll v, e, dem = 0, lof = INT64_MAX, cnt[20000], d[20000], trace[20000];
bool freed[20000];
vector <ll> edge[20000], cost[20000];

void dj()
{

    priority_queue <ii, vector<ii>, Comparison> pq;

    d[1] = 0, cnt[1] = 1;
    pq.push(ii(0, 1));

    while (pq.size() != 0)
    {
        ll u = pq.top().y, du = pq.top().x;
        pq.pop();
        freed[u] = 0;
        //if (du != d[u]) continue;
        if (u == v) break;
        for(ll i = 0; i < edge[u].size(); i++)
        {
            ll v1 = edge[u][i];
            if (d[v1] == d[u] + cost[u][i]) cnt[v1] += cnt[u];
            if (d[v1] > d[u] + cost[u][i])
            { 
                d[v1] = d[u] + cost[u][i];
                cnt[v1] = cnt[u];
                pq.push(ii(d[v1], v1));
            }
        }
    }
}

void process()
{
    For(i, 0, v+2) freed[i] = 1;
    For(i, 0, v+2) d[i] = INT64_MAX;
    memset(cnt, 0, sizeof(cnt));
    
	dj();
	cout << d[v] << ' ' << cnt[v] << endl;
}

void input()
{
	cin >> v >> e;
	For(i, 1, e)
	{
		ll way, A, B, leng;
		cin >> way >> A >> B >> leng;
		edge[A].push_back(B);
		cost[A].push_back(leng);
		if (way == 2)
		{
			edge[B].push_back(A);
			cost[B].push_back(leng);
		}
	}
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
	//cout << "TIME: " << double(clock()-start) / CLOCKS_PER_SEC << endl;
	return 0;
}