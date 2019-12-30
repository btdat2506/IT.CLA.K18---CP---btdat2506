#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, ans, db[100010];
vector <ll> pos (1e7+10, 0);
map <ii, bool> did;

ll min(ll a, ll b, ll c)
{
	return min(a, min(b % c, c % b));
}

void process()
{
	db[0] = db[n+1] = INT64_MAX;
	sort(db+1, db+1+n);
	For(i, 1, n)
	{
		ll res = 1e9, pos1 = 0;
		bool ck = 0;
		pos[db[i]] = i;
		For(j, 1, min(pos[(ll) sqrt(db[i]) + 1], (ll) 1))
		if (db[i] % db[j] == 0 || (db[i] % (ll) (db[i] / db[j]) == 0 && pos[(ll) (db[i] / db[j])] != 0))
		{
			ck = 1;
			break;
		}
		else
			res = min(res, db[i], db[j]);
		res = min(res, db[i], db[i-1]);
		res = min(res, db[i], db[i+1]);
			pos1 = i+1;
		} //TH là số nguyên tố
		if (!ck && res != 1e9) 
		ans += res,
		did[ii(i, pos1)] = 1;
	}
	cout << ans << "\n";
}

void input()
{
	cin >> n;
	For(i, 1, n) cin >> db[i];
}

int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.ok", "w", stdout);
	input();
	process();
}