#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i < b; i++)

ll n, db[50000], xuli[50000], tt[50000];

void process()
{
	set <ll, greater<int> > xuli;
	For(i, 1, n+1)
	{
		xuli.insert(db[i]);
		cout << distance(xuli.begin(), xuli.find(db[i]))+1 << endl;
	}
}

void input()
{
	memset(db, 0, sizeof(db));
	memset(xuli, 0, sizeof(xuli));
	cin >> n;
	For(i, 1, n+1) cin >> db[i];
}

int main()
{
	freopen("KITE.INP", "r", stdin);
	freopen("KITE.OUT", "w", stdout);
	input();
	process();
}