#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll m, n, k, db[310][310];

void deque()
{
	stack <ll> st;
	a[0] = a[n + 1] = INT64_MIN;
	st.push(0);
	For(i, 1, n)
	{
		while (!st.empty() && a[i] <= a[st.top()]) st.pop();
		l1[i] = st.top() + 1;
		st.push(i);
	}
	while (!st.empty()) st.pop();
	st.push(n+1);
	Fod(i, n, 1)
	{
		while (!st.empty() && a[i] <= a[st.top()]) st.pop();
		r1[i] = st.top() - 1;
		st.push(i);
	}

	b[0] = b[n + 1] = INT64_MIN;
	st.push(0);
	For(i, 1, n)
	{
		while (!st.empty() && b[i] <= b[st.top()]) st.pop();
		l2[i] = st.top() + 1;
		st.push(i);
	}
	while (!st.empty()) st.pop();
	st.push(n+1);
	Fod(i, n, 1)
	{
		while (!st.empty() && b[i] <= b[st.top()]) st.pop();
		r2[i] = st.top() - 1;
		st.push(i);
	}
	For(i, 1, n)
	{
		
	}
}

void process()
{
	For(i, 1, n)
	For(X, 1, m)
	For(Y, 1, m)
	a[i] = max(db[X][i], db[Y][i]),
	b[i] = min(db[X][i], db[Y][i]);
	deque();
}

void input()
{
	cin >> m >> n >> k;
	For(i, 1, m)
	For(j, 1, n)
	cin >> db[i][j];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}