 #include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

stack <ll> st;
ll n, next[100010], low[100010], num[100010], ans[100010];

void visit(ll u)
{
	st.push(u);
	low[u] = num[u] = ++cnt;
	{
		ll v = next[u];
		if (num[v])
			low[u] = min(low[u], num[v]);
		else
		{
			visit(v);
			low[u] = min(low[u], low[v]);
		}
	}
	if (low[u] == num[u] && (st.top() != u) || next[u] != u)
	{
		ll cnt = 1;
		while (!st.empty())
		{
			ans[st.top()] = cnt;
			cnt++;
			st.pop();
		}
	}
}

void process()
{
	For(i, 1, n)
	{
		if (next[i] == i) ans[i] = 1; else
		if (!num[i]) visit(i);
	}
	For(i, 1, n)
	cout << ans[i] << "\n";
}

void input()
{
	cin >> n;
	For(i, 1, n)
	cin >> next[i];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}