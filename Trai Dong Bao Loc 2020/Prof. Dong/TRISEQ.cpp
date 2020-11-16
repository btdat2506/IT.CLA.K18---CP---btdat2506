#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;
typedef pair<ll, string> istr;
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define f0(i, n) for(ll i = 0; i < n; i++)
//ifstream (NAME);
//ofstream (NAME);

ll n, k, cnt_state, x[20], a[20], f[20][20][20][20];

ll get_res(ll i, ll mi1, ll mi2, ll ma) //position, min1, min2, max
{
	if (f[i][mi1][mi2][ma] != -1) return f[i][mi1][mi2][ma];
	if (i > n) return 1;
	ll cnt = 0;
	For(v, 1, n)
	{
		ll min1 = mi1, min2 = mi2, maxx = ma;
		if (v < min1)
		{
			min2 = min1;
			min1 = v;
		}
		else
		if (v < min2) min2 = v;
		if (v > maxx) maxx = v;
		if (min1 + min2 > maxx)
		cnt += get_res(i + 1, min1, min2, maxx);
	}
	return f[i][mi1][mi2][ma] = cnt;
}

void config(ll i, ll mi1, ll mi2, ll ma)
{
	if (i > n) return;
	For(v, 1, n)
	{
		int min1 = mi1, min2 = mi2, maxx = ma;
		if (v < min1)
		{
			min2 = min1;
			min1 = v;
		}
		else
		if (v < min2) min2 = v;
		if (v > maxx) maxx = v;

		if (min1 + min2 > maxx)
		{
			if (k > get_res(i+1, min1, min2, maxx))
				k -= get_res(i+1, min1, min2, maxx);
			else
			{
				x[i] = v;
				config(i+1, min1, min2, maxx);
				break; //quên break =.=
			}
		}
	}
}

void get_state(ll i, ll mi1, ll mi2, ll ma)
{
	if (i > n)
	{
		cnt_state++;
		return;
	}
	For(v, 1, a[i])
	{	
		int min1 = mi1, min2 = mi2, maxx = ma;
		if (v < min1)
		{
			min2 = min1;
			min1 = v;
		}
		else
		if (v < min2) min2 = v;
		if (v > maxx) maxx = v;

		if (min1 + min2 > maxx)
		{
			if (v < a[i])
				cnt_state += get_res(i+1, min1, min2, maxx);
			else
				get_state(i+1, min1, min2, maxx);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	memset(f, -1, sizeof(f));
	cin >> n >> k;
	cout << get_res(1, n+1, n+1, 0) << "\n";
	config(1, n+1, n+1, 0);
	For(i, 1, n)
	if (x[i] != 0)
	cout << x[i] << ' '; cout << "\n";
	For(i, 1, n)
	cin >> a[i];
	get_state(1, n+1, n+1, 0);
	cout << cnt_state << "\n";
}