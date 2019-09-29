#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

ll m, n, ans;
char db1[110][110], db2[110][110];

void deque_max(ll *pros, ll siz)
{
	ll l[110], r[110];
	memset(l, 0, sizeof(l));
	memset(r, 0, sizeof(r));
	stack <ll> st;
	pros[0] = pros[siz + 1] = INT64_MIN;
	st.push(0);
	For(i, 1, siz)
	{
		while (!st.empty() && pros[i] <= pros[st.top()]) st.pop();
		l[i] = st.top() + 1;
		st.push(i); 
	}
	while (!st.empty()) st.pop();
	st.push(siz+1);
	Fod(i, siz, 1)
	{
		while (!st.empty() && pros[i] <= pros[st.top()]) st.pop();
		r[i] = st.top() - 1;
		st.push(i);
	}
	For(i, 1, siz)
	ans = max(ans, pros[i] * (r[i] - l[i] + 1));
}

void process_pos()
{
	For(i, 1, m)
	For(j, 1, n)
	{
		ll pros[110];
		memset(pros, 0, sizeof(pros));
		For(i1, 1, i)
		{
			ll low_i = m - i + i1;
			For(j1, 1, j)
			{
				ll low_j = n - j + j1;
				if (db1[i1][j1] == db2[low_i][low_j]) pros[j1]++; else pros[j1] = 0;
			}
		//	For(k, 1, j) cout << pros[k] << endl;
			deque_max(pros, j);
		}
	}
}


void input()
{
	cin >> m >> n;
	For(i, 1, m)
	For(j, 1, n)
	cin >> db1[i][j];

	For(i, 1, m)
	For(j, 1, n)
	cin >> db2[i][j];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ll t;
	cin >> t;
	while (t--)
	{
		memset(db1, '0', sizeof(db1));
		memset(db2, '0', sizeof(db2));
		input();
		process_pos();
		swap(db1, db2);
		process_pos();
		cout << ans << "\n";
	}
}