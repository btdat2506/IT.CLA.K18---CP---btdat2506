#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define vt first
#define val second

typedef pair<ll, ll> ii;

ll n, ans = 0;
bool freed[200000];
ii db[200000];

struct cmp
{
	bool operator () (const ii &L, const ii &R)
	{
		return L.val > R.val;
	}
};

priority_queue<ii, vector<ii>, cmp> pq;

void process()
{
	For(i, 0, 120000) freed[i] = 1;
	while (pq.size() != 0)
	{
		ll u1 = pq.top().vt;
		pq.pop();
		if (freed[u1])
		{
			ans++;
			freed[u1] = freed[u1-1] = freed[u1+1] = 0;
		}
	}
	cout << ans << endl;
}

void input()
{
	cin >> n;
	For(i, 1, n) 
	{
		ll value;
		cin >> value;
		pq.push(ii(i, value));
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}