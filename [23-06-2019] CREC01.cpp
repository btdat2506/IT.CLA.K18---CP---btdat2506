#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll m, n, ans = 0, f[1010], h[1010], l[1010];

void process()
{
	stack <ll> st;
	memset(l, 0, sizeof(l));
	l[0] = l[n+1] = INT64_MIN;
	st.push(0);
	For(i, 1, n)
	{
		while (!st.empty() && h[i] <= h[st.top()]) st.pop();
		if (st.empty()) l[i] = 1; else
		l[i] = st.top() + 1; 
		st.push(i);
	}
	For(i, 1, n)
	{
		ll k = l[i] - 1;
		f[i] = h[i] * (i - k) + f[k];
		ans += f[i];
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> m >> n;
	For(i, 1, m)
	{
		For(j, 1, n)
		{
			char x;
			cin >> x;
			if (x == '1') h[j]++;
			else h[j] = 0;
		}
		process();
	}
	cout << ans << endl;
}