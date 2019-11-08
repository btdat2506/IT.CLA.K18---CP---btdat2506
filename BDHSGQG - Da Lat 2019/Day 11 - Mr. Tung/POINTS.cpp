#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define MOD 
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, negx, negy, posx, posy;

ll operator * (ll a, ll b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}

ll giaithua(ll u)
{
    ll tmp = giaithua(u/2);
    if (u % 2 != 0)
    return (tmp * tmp * u) % MOD;
    return (tmp * tmp) % MOD;
}

ll cnk(ll k, ll n)
{
    if (k > n) return 0;
    return (fact[i] * re_fact[i]) % MOD 
}

void process()
{
    ll ans = 0;
    For(points, 0, n) //p++
    {
        ll pos = posx - points;
        ll diff = negy - pos;
        ll neg = negx - diff; //to hop chap p-+ tren x-
        if (pos >= 0 && diff >= 0 && neg >= 0)
        {
            ll cntx = (cnk(posx, points) * cnk(negx, diff));
            ll cnty = (cnk(posy, points) * cnk(negy, diff));
            ans = (ans + (cntx * cnty) % MOD) % MOD;
        }
    }
}

void input()
{
    cin >> n;
    For(i, 1, n)
    {
        ll x;
        cin >> x;
        if (x > 0) posx++; else negx--;
    }
    For(i, 1, n)
    {
        ll y;
        cin >> y;
        if (y > 0) posy++; else negy--;
    }
}

int main()
{
    freopen("POINTS.INP", "r", stdin);
    freopen("POINTS.OUT", "w", stdout);
    input();
    process();
}