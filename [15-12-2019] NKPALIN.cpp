#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

ll n, leng[2010][2010];
string st;

string ans()
{
	string res = "";
	ll i = n, j = n;
	while (leng[i][j] > 0)
	{
		if (st[i] == st[n-j+1])
			res += st[i], i--, j--;
		else
		if (leng[i-1][j] > leng[i][j-1])
			i--;
		else
			j--;
	}
	reverse(res.begin(), res.end());
	return res;
}

void process()
{
	For(i, 1, n)
	For(j, 1, n)	
	if (st[i] == st[n-j+1])
		leng[i][j] = leng[i-1][j-1] + 1;
	else
		leng[i][j] = max(leng[i-1][j], leng[i][j-1]);
	cout << ans() << '\n';
}

int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.ok", "w", stdout);
	cin >> st;
	n = st.length();
	st = ' ' + st;
	process();
}