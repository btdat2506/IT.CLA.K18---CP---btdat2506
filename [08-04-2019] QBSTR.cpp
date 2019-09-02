#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

string st1, st2;

void process()
{
	ll siz = max(st1.length(), st2.length()),
	n = st1.length(),
	m = st2.length();
	vector < vector<ll> > f (siz+1, vector<ll> (siz+1, 0));
	For(i, 1, n)
	For(j, 1, m)
	if (a[i] == b[j])
	{
		f[i][j] = f[i-1][j-1] + 1;
	}
	else
	f[i][j] = max(f[i-1][j], f[i][j-1]);
	cout << f[n][m] << endl;
}

void input()
{
	getline(cin, st1);
	getline(cin, st2);
}

int main()
{
	input();
	process();
}