#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;
#define x first
#define y second
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, q, notGonnaMadeIt;
bool notPassable[4][100010];
set <ll> road[3];
ii pt[100010];

void process()
{
    For(i, 1, q)
    {
        ll u = pt[i].x, v = pt[i].y;
        notPassable[u][v] = !notPassable[u][v];
        ll delta = (notPassable[u][v]) ? 1 : -1;
        For(j, -1, 1)
        notGonnaMadeIt += (notPassable[3-u][v+j] && v+j <= n && v+j >= 1) ? delta : 0;
        if (notGonnaMadeIt)
            cout << "No" << "\n";
        else
            cout << "Yes" << "\n";
    }
}

void input()
{
    cin >> n >> q;
    For(i, 1, q)
    cin >> pt[i].x >> pt[i].y;
}

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    input();
    process();
}



