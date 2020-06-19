#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

//start: 10h04
//end:

ll n, m, ans, one[100], zero[100];

void process()
{
    ll l = 1, r = n + m;
    For(i, 1, (n + m - 1) / 2)
    {
        ll l = i, r = n + m - i;
        ans += min(abs(one[l] + one[r]), abs(zero[l] + zero[r]));
    }
    cout << ans << "\n";
}

void input()
{
    cin >> n >> m;
    For(i, 1, n)
    For(j, 1, m)
    {
        bool state;
        cin >> state;
         one[i + j - 1] += (ll)  state;
        zero[i + j - 1] += (ll) !state;
    }
}

void init()
{
    memset(one, 0, sizeof(one));
    memset(zero, 0, sizeof(zero));
    ans = 0;
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
        init();
        input();
        process();
    }
}