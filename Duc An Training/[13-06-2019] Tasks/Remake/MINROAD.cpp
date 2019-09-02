#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

struct dt
{
	ll idx = 0, len = 0, type = 0, tung = 0, truc = 0;
	bool operator < (const dt &op)
	{
		return len < op.len;
	}
};

bool check(ll pos, ll start)
{
	if (db[pos].tung - db[start-1].tung >= a && 
		db[pos].truc - db[start-1].truc >= b)
	return 1; else
	return 0;
}

dt db[300010];

void process()
{
	sort(db+1, db+1+n);
	For(i, 1, n)
	db[i].tung = ((db[i].type) == 1 ? 1 : 0) + db[i-1].tung,
	db[i].truc = ((db[i].type) == 2 ? 1 : 0) + db[i-1].truc;
	if (db[n].tung < a || db[n].truc < b)
	{
		cout << -1 << endl;
		return;
	}
	For(i, 1, n)
	{
		ll mid = (n + i) / 2,
		   left = i,
		   right = n;
		while (left < right)
		{
			if (check(mid, left))
				right = mid,
				mid = (left + right) / 2;
			else
				left = mid,
				mid = (left + right) / 2;
		}
		if (!check(mid, i)) return;
		ans = min(ans, db[mid].len - db[i].len);
	}
	cout << ans << endl;
}

void input()
{
	cin >> n >> a >> b;
	For(i, 1, n)
	cin >> db[i].len >> db[i].type;
}

int main()
{
	freopen("MINROAD.INP", "r", stdin);
	freopen("MINROAD.OUT", "w", stdout);
	input();
	process();
}