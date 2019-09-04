#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

typedef pair<ll, ll> ii;

bool isPrime[110] = {};
ll m, n, db[200][200], pros[200][200], cnt[200][200];

struct dat
{
	ll x, y, x_pre, y_pre;
	dat (ll _x = 0, ll _y = 0, ll _x_pre = 0, ll _y_pre = 0)
	{
		x = _x, y = _y, x_pre = _x_pre, y = _y_pre;
	}
};

void snt()
{
	For(i, 1, 105) isPrime[i] = 1;
	isPrime[0] = isPrime[1] = 0;
	For(i, 2, sqrt(100))
	for(ll j = i*i; j <= 100; j+=i)
		isPrime[j] = 0;
}

void process()
{
	queue < dat > q;
	if (isPrime[db[2][1] - db[1][1]]) 
	{
		q.push(dat(2, 1, 1, 1));
		cnt[2][1]++;
	}
	if (isPrime[db[1][2] - db[1][1]]) 
	{
		q.push(dat(1, 2, 1, 1));
		cnt[2][1]++;
	}
	while (!q.empty())
	{
		ll x = q.front().x, y = q.front().y,
		   x_pre = q.front().x_pre, y_pre = q.front().y_pre;
		q.pop();
		if (isPrime[db[x+1][y] - db[x_pre][y_pre]]) 
		{
			q.push(dat(x+1, y, x_pre, y_pre));
			cnt[x][y]++;
		}
		if (isPrime[db[x][y+1] - db[x_pre][y_pre]]) 
		{
			q.push(dat(x, y+1, x_pre, y_pre));
			cnt[x][y]++;
		}
	}
}

void input()
{
	memset(db, 0, sizeof(db));
	memset(cnt, 0, sizeof(cnt));
	memset(pros, 0, sizeof(pros));
	cin >> m >> n;
	For(i, 1, m)
	For(j, 1, n)
	{
		cin >> db[i][j];
		pros[i][j] = db[i][j];
	}
}

int main()
{
	freopen("ROBOT.INP", "r", stdin);
	freopen("ROBOT.OUT", "w", stdout);
	input();
	process();	
}