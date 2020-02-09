#include <bits/stdc++.h>

using namespace std;

//begin: 16:09 Feb 07 Friday
//end: 

typedef int64_t ll;
typedef pair<ll ,ll> pll;
#define vert first //vertical
#define horiz second //horizontal
#define For(i, a, b) for(ll i = a; i <= b; i++)

pll ans;
ll n, arr[300000];

pll min(pll a, pll b)
{
    if (a.second-a.first < b.second-b.first)
        return a;
    else
        return b;
}

void process()
{
    map <pll, ll> pos;
    pll           cur;
    ans = pll(0, 0);
    pos[cur] = 1;
    For(i, 1, n)
    {
        ll x = 0, y = 0;
        if (abs(arr[i]) == 1) cur.vert += arr[i]; else cur.horiz += arr[i];
        if (pos[cur]) 
            {
                if (ans == pll(0, 0))
                ans = pll(pos[cur], i);
                else
                ans = min(pll(pos[cur], i), ans);
            }
        pos[cur] = i + 1;
    }
    if (ans == pll(0, 0))
        cout << -1 << "\n";
    else
        cout << ans.first << ' ' << ans.second << "\n";
}

void input()
{
    cin >> n;
    For(i, 1, n)
    {
        char tmp;
        cin >> tmp;
        if (tmp == 'U') arr[i] =  2;
        if (tmp == 'D') arr[i] = -2;
        if (tmp == 'L') arr[i] = -1;
        if (tmp == 'R') arr[i] =  1;
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    ll t;
    cin >> t;
    while (t--)
    {
        input();
        process();
    }
}