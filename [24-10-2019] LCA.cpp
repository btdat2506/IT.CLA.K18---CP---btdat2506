#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define MAXN 1010
#define level 10 //log2(MAXN)
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, m, depth[MAXN];
ll parent[MAXN][level];
vector <ll> edge[MAXN];

void dfs(int cur, int prev) 
{ 
    depth[cur] = depth[prev] + 1; 
    parent[cur][0] = prev; 
    for (int i=0; i<edge[cur].size(); i++) 
    { 
        if (edge[cur][i] != prev) 
            dfs(edge[cur][i], cur); 
    } 
}

void precomputeSparseMatrix() 
{ 
    for (int i=1; i<level; i++) 
    for (int node = 1; node <= n; node++) 
    { 
        if (parent[node][i-1] != -1) 
            parent[node][i] = 
            	parent[parent[node][i-1]][i-1]; 
    } 
} 

ll lca(ll u, ll v) 
{ 
    if (depth[v] < depth[u]) 
        swap(u, v); 
  
    ll diff = depth[v] - depth[u]; 
  
    // Step 1 of the pseudocode 
    for (ll i=0; i<level; i++) 
        if ((diff>>i)&1) 
            v = parent[v][i]; 
  
    if (u == v) return u; 
 
    // Step 2 of the pseudocode 
    for (ll i=level-1; i>=0; i--) 
        if (parent[u][i] != parent[v][i]) 
        { 
            u = parent[u][i]; 
            v = parent[v][i]; 
        } 
  
    return parent[u][0]; 
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ll t;
	cin >> t;
	For(test, 1, t)
	{
		memset(parent, -1, sizeof(parent));
		memset(depth, 0, sizeof(depth));
		cin >> n;
		For(i, 1, n)
		{
			edge[i].clear();
			cin >> m;
			For(j, 1, m)
			{
				ll x;
				cin >> x;
				//parent[x][0] = i;
				//depth[x] = depth[i] + 1;
				edge[i].push_back(x);
				edge[x].push_back(i);
				//có 2 cách, hoặc là gán parent và depth ngay, hoặc là cho chạy dfs.
			}
		}
		dfs(1, 0);
		precomputeSparseMatrix();
		cout << "Case " << test << ": \n";
		ll q;
		cin >> q;
		while (q--)
		{
			ll x, y;
			cin >> x >> y;
			cout << lca(x, y) << "\n";
		}
	}
}