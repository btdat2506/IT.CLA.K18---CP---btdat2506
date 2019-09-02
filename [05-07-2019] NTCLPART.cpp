#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

double RATIO = 0;
ll n, db[1100], f[1100], trace[1100];

bool check(ll i, ll j)
{
	double cal = double(double(i - j + 1) / double(db[i] - db[j] + 1));
	if (cal > RATIO) return 1;
	if (fabs(cal - RATIO) <= DBL_EPSILON) return 1;
	return 0;
}

void process()
{
	For(i, 0, n) f[i] = INT64_MAX;
	For(i, 1, n) trace[i] = i-1;
	f[0] = 0;
	For(i, 1, n)
	Fod(j, i, 0)
	{
		bool ck = check(i, j);
		if (ck && f[i] > f[j-1] + 1)
			f[i] = f[j-1] + 1,
			trace[i] = j-1;
	}
	cout << f[n] << endl;
	if (f[n] != 1)
	{
		stack <ll> st;
		st.push(trace[n]);
		while (trace[st.top()] != 0) st.push(trace[st.top()]);
		while (!st.empty())
		{
			cout << st.top() << endl;
			st.pop();
		}
	}
}

void input()
{
	cin >> n >> RATIO;
	For(i, 1, n) cin >> db[i];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}