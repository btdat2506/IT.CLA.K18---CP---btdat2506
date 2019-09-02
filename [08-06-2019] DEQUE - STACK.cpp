#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

ll m, n, ans = 0, db[1010], calc[1010], l[1010], r[1010];

void process()
{
	stack <ll> st;
	calc[0] = calc[n + 1] = INT64_MIN;
	st.push(0);
	For(i, 1, n)
	{
		while (!st.empty() && calc[i] <= calc[st.top()]) st.pop();
		l[i] = st.top() + 1;
		st.push(i);
	}
	while (!st.empty()) st.pop();
	st.push(n+1);
	Fod(i, n, 1)
	{
		while (!st.empty() && calc[i] <= calc[st.top()]) st.pop();
		r[i] = st.top() - 1;
		st.push(i);
	}
	For(i, 1, n)
	ans = max(ans, calc[i] * (r[i]-l[i]+1));
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	cin >> m >> n;
	For(i, 1, m)
	{
		memset(db, 0, sizeof(db));
		memset(l, 0, sizeof(l));
		memset(r, 0, sizeof(r));
		For(j, 1, n)
		{
			cin >> db[j];
			if (db[j]) calc[j]++; else calc[j] = 0;
		}
		process();
	}
	cout << ans << endl;
}