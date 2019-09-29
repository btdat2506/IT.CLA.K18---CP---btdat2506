#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll visit(ll u)
{
	if (visited[u] != t)
		visited[u] = t;
	else
		return 0;
	for(ll v: db[u])
	if (!Assigned[v] || visit(Assigned[v]))
	{
		Assigned[v] = u;
		return 1;
	}
	return 0;
}