#include <bits/stdc++.h>

using namespace std;

typedef int32_t ll;
typedef pair<ll, ll> ii;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, db[500010];
ii res[500010];
vector <ll> Prime (1e7+10);

void sieve() //sàng nguyên tố sai đéo vì lí do gì? :)
{
    Prime[1] = 2;
    For(i, 2, 1e7) Prime[i] = i;
    For(i, 2, sqrt(1e7)+10)
    if (Prime[i] == i)
    {
        for(ll j = i * i; j <= 1e7; j += i)
        if (Prime[j] == j)
            Prime[j] = i;
    }
}

ii get_divisors(ll num)
{
    ll d1 = 1, d2 = num;
    while (d2 % Prime[num] == 0) //đừng lộn với prime[d2]
        d2 /= Prime[num];
    d1 = num / d2;
    if (d1 != 1 && d2 != 1 && __gcd(d1 + d2, num) == 1)
        return ii(d1, d2);
    return ii(-1, -1);
}

void process()
{
    For(i, 1, n)
    res[i] = get_divisors(db[i]);
    For(i, 1, n)
    cout << res[i].first << ' '; cout << "\n";
    For(i, 1, n)
    cout << res[i].second << ' '; cout << "\n";
}

void input()
{
    cin >> n;
    For(i, 1, n)
    cin >> db[i];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    sieve();
    input();
    process();
}