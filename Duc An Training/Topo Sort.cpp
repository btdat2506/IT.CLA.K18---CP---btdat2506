#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

bool visited[100010];
stack <ll> st;
vector <ll> edge[100010];
ll n, m;

void topo_sort_traversal(ll u) 
{
	visited[u] = 1;
	for(ll v: edge[u])
	if (!visited[v]) topo_sort_traversal(v);
	st.push(u);
}

void toposort()
{
	For(i, 0, n)
	if (!visited[i]) topo_sort_traversal(i);
	while (!st.empty())
	{
		cout << st.top() << endl;
		st.pop();
	}
}

void input()
{
	cin >> n >> m;
	For(i, 1, m)
	{
		ll x, y;
		cin >> x >> y;
		edge[x].push_back(y);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	toposort();
}