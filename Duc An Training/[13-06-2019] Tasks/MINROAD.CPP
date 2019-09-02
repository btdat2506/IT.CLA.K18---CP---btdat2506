#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

typedef pair <ll, ll> ii;

bool cmp (const ii &l, const ii &r)
{
	return l.x < r.x;
}

ii db[300020];
ll n, a, b, ans = -1;

void process()
{
	sort(db+1, db+1+n, cmp);
	For(i, 2, n)
	{
		ll leng = 0, cnta = 0, cntb = 0;
		Fod(j, i, 1)
		{
			leng = db[i].x - db[j].x;
			if (db[j].y == 1) cnta++; else cntb++;
			if (cnta >= a && cntb >= b)
			{
				ans = leng;
				break;
			} 
		}
	}
	cout << ans << endl;
}

void input()
{
	cin >> n >> a >> b;
	For(i, 1, n)
	{
		ll x_temp, y_temp;
		cin >> x_temp >> y_temp;
		db[i]= ii(x_temp, y_temp);
	}
}

int main()
{
	freopen("MINROAD.INP", "r", stdin);
	freopen("MINROAD.OUT", "w", stdout);
	input();
	process();	
}