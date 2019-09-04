void visit(ll u, ll p)
{
	ll num_child = 0;
	low[u] = num[u] = ++Time;
	for(ll v: db[u])
	if (v != p)
	{
		if (num[v])
			low[u] = min(low[u], num[v]);
		else
		{
			num_child++;
			visit(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] >= num[v])
				bridges++;
			if (u == p)
			{
				if (num_child == 2)
					cut_vectex[u] = 1;
			}
			else
			if (low[v] >= num[u]) cut_vectex[u] = 1;
		}
	}
}