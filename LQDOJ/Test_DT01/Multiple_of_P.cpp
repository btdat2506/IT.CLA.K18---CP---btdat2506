#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef uint64_t ull;
typedef pair<ll, ll> ii;
#define fi first
#define se second
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, P, ans, arr[100010];
map <ll, ii> cnt;
map <ll, bool> used;

void cnt_for_p()
{
	ll num = 0, tmp = P;
	while (tmp != 0)
		num++,
		tmp /= 10;
	cnt[P].se = num;
}

void process()
{
	cnt_for_p();
	ull t;
	ll pos;
	sort(arr+1, arr+1+n);
	For(i, 1, n)
	{
		cnt[arr[i]].fi++;
		if (cnt[arr[i]].se == 0)
		{
			ll num = 0, tmp = arr[i];
			while (tmp != 0)
				num++,
				tmp /= 10;
			cnt[arr[i]].se = num;
		}
	}
	For(i, 1, n)
	if (cnt[arr[i]].se + cnt[P].se < 20)
	{
		t = (ull) ((ull) arr[i] * (ull) P);
		if (t <= (ull) 1e18)
		{
			pos = (cnt[t].fi < cnt[i].fi) ? t : i;
			used[t] = used[i] = 1;
			if (!used[pos])
				ans += cnt[pos].fi;
		}
		/* if (!used[t] && cnt[t].fi != 0)
			ans += cnt[t].fi,
			used[t] = 1; */
	}
	cout << n - ans << "\n";
}

void input()
{
	cin >> n >> P;
	For(i, 1, n)
	cin >> arr[i];
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("test.in", "r", stdin);
	freopen("test.ok", "w", stdout);
	input();
	process();
}