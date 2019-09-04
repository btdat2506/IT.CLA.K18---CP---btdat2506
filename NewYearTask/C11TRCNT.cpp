#include <bits/stdc++.h>

using namespace std;
#define For(i, a ,b) for(int64_t i = a; i <= b; i++)
#define ll int64_t
#define X first
#define Y second
#define mp make_pair

ll n, dem[400], ans;
pair <ll, ll> a[400];

bool check(ll i, ll j, ll k) //cong thuc kiem tra 3 diem thang hang xab/yab == xac/yac
{
	ll xab = a[j].X - a[i].X, yab = a[j].Y - a[i].Y;
	ll xac = a[k].X - a[i].X, yac = a[k].Y - a[i].Y;
	return (ll)xab * yac != (ll)xac * yab;
}

int main()
{
    cin >> n;
    For(i, 1, n)
    {
        ll c, d;
        cin >> c >> d;
        a[i] = mp(c, d);
    }
    For(i, 1, n)
    For(j, i+1, n)
    For(k, j+1, n)
    if (check(i, j, k))
    {
        ans++;
        dem[i]++;
        dem[j]++;
        dem[k]++;
    }
    ll t = dem[1];
    For(i, 1, n) if (dem[i] < dem[t]) t = i;
    cout << ans << ' ' << t;
}