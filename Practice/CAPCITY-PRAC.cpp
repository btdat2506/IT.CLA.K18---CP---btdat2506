#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

bool scc_belongs[10010];
ll n, m, cnt1, cnt, low[10010], num[10010];
vector <ll> db[10010], scc[10010];
stack <ll> st;

void visit(ll u)
{
	low[u] = num[u] = ++cnt1;
	st.push(u);
	for(ll v: db[u])
	if (num[v])
		low[u] = min(low[u], num[v]);
	else
	{
		visit(v);
		low[u] = min(low[u], low[v]);
	}
	if (num[u] == low[u])
	{
		ll v = -1, siz = 0;
		if (st.top() != u)
		{
			scc_size++;
			while (u != v)
			{
				v = st.top();
				st.pop();
				num[v] = low[v] = INT64_MAX;
				scc[scc_size].push_back(v);
			}
		}
	}
}

void process()
{
	For(i, 1, n)
	if (!num[i]) visit(i); //thăm các đỉnh

	//chỉnh các đỉnh thuộc scc về 1 đỉnh
	memset(scc_belongs, 0, sizeof(scc_belongs));
	For(i, 1, scc_size)
	
	
	
	

	queue <ll> ans;
	For(i, 1, n)
	if (num[i] == INT64_MAX && low[i] == INT64_MAX) ans.push(i);
	cout << ans.size() << endl;
	while (!ans.empty())
	{
		cout << ans.front() << ' ';
		ans.pop();
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n >> m;
	For(i, 1, m)
	{
		ll x, y;
		cin >> x >> y;
		db[x].push_back(y);
	}
	process();
}