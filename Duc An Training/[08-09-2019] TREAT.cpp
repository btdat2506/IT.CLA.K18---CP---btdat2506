 #include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

stack <ll> st;
ll n, cnt1, nxt[100010], low[100010], num[100010], ans[100010];

void visit(ll u)
{
	st.push(u);
	low[u] = num[u] = ++cnt1;
	{
		ll v = nxt[u];
		if (num[v])
			low[u] = min(low[u], num[v]);
		else
		{
			visit(v);
			low[u] = min(low[u], low[v]);
		}
	}
	if (low[u] == num[u] && ((st.top() != u) || nxt[u] != u))
	{
		ll cnt = 1;
		while (!st.empty())
		{
			cout << st.top() << ' ';
			ans[st.top()] = cnt;
			cnt++;
			st.pop();
		}
		cout << endl;
	}
}

void process()
{
	For(i, 1, n)
	{
		memset(low, 0, sizeof(low));
		memset(num, 0, sizeof(num));
		if (nxt[i] == i) ans[i] = 1; else
		visit(i);
	}
	For(i, 1, n)
	cout << ans[i] << "\n";
}

void input()
{
	cin >> n;
	For(i, 1, n)
	cin >> nxt[i];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}