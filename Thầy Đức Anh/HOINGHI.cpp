#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, k, cnt, qu[200], steps[200];
bool a[200][200];

void process()
{
	
		ll R = 0;
		For(j, 1, n)
		{
			if (!a[*s.begin()][j])
			{
				qu[++R] = j;
				For(l, 1, R)
				if (a[j][qu[l]])
				{
					R--;
					break;
				}
			}
		}
		cout << "ngay " << ++cnt << " : " << *s.begin();
		s.erase(s.begin());
		For(i, 1, n)
		a[*s.begin()][i] = a[i][*s.begin()] = 1;
		For(j, 1, min(k, R))
		{
			cout << ',' << qu[j];
			s.erase(qu[j]);
			For(i, 1, n)
			a[qu[j]][i] = a[i][qu[j]] = 1;
		}
}

void input()
{
	cin >> n >> k;
	For(i, 1, n)
	{
		string st;
		stringstream ss;
		cin >> st;
		ss << st;
		ll x1;
		ss >> x1;
		for(ll x; ss >> x;)
		a[x1][x] = 1,
		steps[x1]++;
	}
}

int main()
{
	freopen("HOINGHI.INP", "r", stdin);
	freopen("HOINGHI.OUT", "w", stdout);
	input();
	process();
}