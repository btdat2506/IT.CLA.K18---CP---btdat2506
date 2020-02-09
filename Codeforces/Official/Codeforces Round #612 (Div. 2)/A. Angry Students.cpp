#include <bits/stdc++.h>

using namespace std;

//begin: 18:51
//end: 19:00

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, ans;
string st;

void process()
{
    for(ll i = 0, j = 0; i < n && j < n;)
    {
        while (st[i] != 'A' && i < n) i++; j = i + 1;
        while (st[j] != 'A' && j < n) j++;
        ans = max(ans, j - i - 1);
        i = j;
    }
    cout << ans << "\n";
}
    
void input()
{
    cin >> n >> st;
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
        ans = 0;
        input();
        process();
    }
}