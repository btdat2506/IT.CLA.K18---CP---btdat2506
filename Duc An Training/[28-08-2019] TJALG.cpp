#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

stack <ll> st;
ll n, m, cnt1, cnt, visited[10010], low[10010], num[10010];
vector <ll> db[10010];

void visit(ll u)
{
	low[u] = num[u] = ++cnt1;
	for(auto v: db[u])
	if (num[v])
		low[u] = min(low[u], num[v]);
	else
	{
		visit(v);
		num[v] = min(num[u], num[v]);
	}
	if (low[u] == num[u])
	{
		ll v = -1;
		while (u != v)
		{
			v = st.top();
			st.pop();
			low[u] = low[v] = INT64_MAX;
		}
		cnt++;
	}
	else st.push(u);
}

void process()
{
	For(i, 1, n)
	if (!visited[i]) visit(i);
	cout << cnt << endl
;}

void input()
{
	cin >> n >> m;
	For(i, 1, m)
	{
		ll x, y;
		cin >> x >> y;
		db[x].push_back(y);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}