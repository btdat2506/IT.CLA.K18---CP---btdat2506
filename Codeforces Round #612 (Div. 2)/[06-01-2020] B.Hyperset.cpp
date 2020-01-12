#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

ll n, k, ans;
string st[1600], temp;
map <string, ll> isExist;

void process()
{
	For(i, 1, n) isExist[st[i]]++;
	temp = st[1];
	For(i, 1, n-1)
	For(j, i+1, n)
	{
		For(l, 1, k)
		{
			if (st[i][l] == st[j][l]) temp[l] = st[i][l]; else
			temp[l] = 'S' + 'E' - st[i][l] + 'T' - st[j][l];
		}
		ans += isExist[temp];
	}
	cout << ans/3 << "\n";
}

void input()
{
	cin >> n >> k;
	For(i, 1, n)
	{
		cin >> st[i];
		st[i] = ' ' + st[i];
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("test.in", "r", stdin);
	freopen("test.ok", "w", stdout);
	input();
	process();
}