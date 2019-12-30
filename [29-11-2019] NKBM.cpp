#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

vector <ll> edge[110];

void process()
{
	
}

void input()
{
	ll a, b, m;
	cin >> a >> b >> m;
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
	process();
}