#include <bits/stdc++.h>

//begin 9h30pm, end: 

using namespace std;

#define For(i, a, b) for(ll i = a; i < b; i++)
#define ll int64_t

struct database
{
    ll x = 0, y = 0, s = 0;
};

ll k, r, m, n;

database query[200], slot[200];

bool getBit(ll x, ll y)
{
    return (x >> y) & 1;
}

bool check(ll state) 
{
    ll temp = 0;
    For(i, 0, m)
    temp += getBit(state, i);
    if (temp == k) return 1; return 0;
}

ll cal(ll x1, ll x2, ll y1, ll y2)
{
    return ceil(sqrt((x1 - x2) *  (x1 - x2) + (y1 - y2) * (y1 - y2)));
}

ll total(ll state, ll *used)
{
    ll temp = 0;
    For(i, 0, n)
    if (cal(slot[i].x, slot[i].y, query[state].x, query[state].y) <= r and !used[i])
    {
        temp += slot[i].s;
        used[i] = 1;
    }
    return temp;
}

void process()
{
    ll ans = 0;
    For(state, 0, 1 << m)
    if (check(state))
    {
        ll tmp = 0, used[n+10];
        memset(used, 0, sizeof(used)); 
        For(i, 0, m)
        if (getBit(state, i)) ans = max(ans, total(i, used));
    }
    cout << ans << endl;
}

void input()
{
    cin >> k >> r >> m;
    For(i, 0, m) cin >> query[i].x >> query[i].y;
    cin >> n;
    For(i, 0, n) cin >> slot[i].x >> slot[i].y >> slot[i].s;
}

int main()
{
    input();
    process();
}