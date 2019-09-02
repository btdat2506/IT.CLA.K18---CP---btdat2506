#include <bits/stdc++.h>

using namespace std;

#define inf INT64_MIN
#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

ll n, k, a[18000], L[18000], R[18000], ans[18000];

void process()
{
	stack <ll> st;
	st.push(0);
	For(i, 1, n)
	{
		while (a[i] <= a[st.top()]) st.pop();
		L[i] = st.top() + 1;
		st.push(i);
	}
	while (st.size() != 0) st.pop();
	st.push(n+1);
	Fod(i, n, 1)
	{
		while (a[i] <= a[st.top()]) st.pop();
		R[i] = st.top() - 1;
		st.push(i);
	}
	For(i, 1, n)
	For(j, max(i-k+1, L[i]), min(i, R[i] - k + 1))
		if (ans[j] == inf) ans[j] = a[i];
	For(i, 1, n-k+1) cout << ans[i] << ' ';
	cout << endl;
}

void input()
{
	memset(a, 0, sizeof(a));
	memset(L, 0, sizeof(L));
	memset(R, 0, sizeof(R));
	For(i, 0, 17500) ans[i] = inf;
	cin >> n >> k;
	For(i, 1, n) cin >> a[i];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ll t;
	cin >> t;
	For(i, 1, t)
	{
		input();
		process();	
	}
}