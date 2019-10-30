#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, m, s, t;
vector <ll> edge[100010];

void visit(ll u)
{
	Num[u] = Low[u] = ++cnt1;
	for(ll v: edge[u])
}

void process()
{

}

void input()
{
	cin >> n >> m >> s >> t;
	For(i, 1, m)
	{
		ll u, v;
		cin >> u >> v;
		edge[u].push_back(v);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}