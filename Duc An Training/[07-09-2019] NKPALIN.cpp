#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

struct db
{
	string st = "";
	ll leng = 0;
};

ll n;
string st, st1;
db lcs[2010][2010];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> st;
	st1 = st;
	reverse(st1.begin(), st1.end());
	n = st.length();
	st = ' ' + st;
	st1 = ' ' + st1;
	For(i, 1, n)
	For(j, 1, n)
	{
		if (st[i] == st1[j])
		{
			lcs[i][j].leng = lcs[i-1][j-1].leng + 1;
			lcs[i][j].st = lcs[i-1][j-1].st + st[i];
		}
		else
		{
			if (lcs[i-1][j].leng > lcs[i][j-1].leng)
				lcs[i][j] = lcs[i-1][j];
			else
				lcs[i][j] = lcs[i][j-1];
		}
	}
	cout << lcs[n][n].st << endl;
}