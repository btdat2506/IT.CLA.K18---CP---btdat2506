#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;
typedef pair<ll, string> istr;
typedef tuple<ll, ll, ll> iii;
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define f0(i, n) for(ll i = 0; i < n; i++)
//ifstream (NAME);
//ofstream (NAME);

ll n, k;
tuple <ll, ll, ll> a[1000010];
vector <ll> t;
priority_queue <iii, vector<iii> > pq;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	f0(i, n)
	{
		ll s, d, r;
		cin >> s >> d >> r;
		d += k;
		pq.push(tie(r, s, d));
	}
	while (!pq.empty())
	{
		
	}
}