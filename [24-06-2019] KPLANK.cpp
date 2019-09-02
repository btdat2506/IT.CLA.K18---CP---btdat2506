#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

ll n, ans, s, l[1000010], r[1000010], db[1000010];

void process()
{
	stack <ll> st;
	st.push(0);
	db[0] = db[n+1] = INT64_MIN;
	For(i, 1, n)
	{
		while (!st.empty() && db[i] <= db[st.top()]) st.pop();
		l[i] = (st.empty()) ? 1 : st.top() + 1;
		st.push(i);
	}
	while (!st.empty()) st.pop();
	st.push(n+1);
	Fod(i, n, 1)
	{
		while (!st.empty() && db[i] <= db[st.top()]) st.pop();
		r[i] = (st.empty()) ? n : st.top() - 1;
		st.push(i);
	}
	For(i, 1, n)
	if ((r[i] - l[i] + 1) >= db[i] && db[i] > ans)
		ans = db[i];
	cout << ans << endl;
}

void input()
{
	cin >> n;
	For(i, 1, n) cin >> db[i];
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
} 