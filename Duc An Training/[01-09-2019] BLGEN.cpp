#include <bits/stdc++.h>

using namespace std;

#define ll uint64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

bool notPrime[2200000];
ll n, m, db1[1010], db2[1010], lcs[1010][1010];

void sieve()
{
	notPrime[0] = notPrime[1] = 1;
	For(i, 2, sqrt(2200000) + 1)
	for(ll j = i*i; j <= 2200000; j += i)
	notPrime[j] = 1;
}

bool kt(ll i, ll j)
{
	ll x = round(pow(db1[i], 0.5)), y = round(pow(db1[i], 1.0/3.0)); //không dùng sqrt và cbrt để tránh sai số
	if (db1[i] == db2[j] && (x*x == db1[i] || (y*y*y == db1[i] && !notPrime[y]))) return 1;
	return 0;
}

void process()
{
	For(i, 1, m)
	For(j, 1, n)
	{
		if (kt(i, j)) lcs[i][j] = lcs[i-1][j-1] + 1;
		else
		lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
	}
	cout << lcs[m][n] << endl;
}

void input()
{
	string st;
	getline(cin, st);
	stringstream ss;
	ss << st;
	for(ll x; ss >> x;) db1[++m] = x;
	getline(cin, st);
	stringstream ss2;
	ss2 << st;
	for(ll x; ss2 >> x;) db2[++n] = x;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	sieve();
	process();
}