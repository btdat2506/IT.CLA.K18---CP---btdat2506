#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

stack <ll> st;
vector <ll> db[100010];
ll n, m, cnt, cnt1, low[100010], num[100010];

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
	if (low[u] == num[u])
	{
		cnt++;
		ll v = -1;
		while (u != v)
		{
			v = st.top();
			st.pop();
			low[v] = num[v] = INT64_MAX; //remove
		}
	}

}

void process()
{
	For(i, 1, n)
	if (num[i] == 0) visit(i);
	cout << cnt << endl;
}

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