ll lca(ll u, ll v)
{
	if (h[u] < h[v]) swap(u, v);
	while (h[u] > h[v]) u = parent[u];
	while (u != v)
	{
		u = parent[u];
		v = parent[v];
	}
	return u;
}