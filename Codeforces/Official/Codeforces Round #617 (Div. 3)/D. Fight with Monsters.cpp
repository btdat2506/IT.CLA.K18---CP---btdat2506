#include <bits/stdc++.h>

using namespace std;

//begin: 13:16 Feb 08 Saturday
//end: 

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, a, b, k, ans, h[300000];

void process()
{
    For(i, 1, n)
    {
        h[i] = (h[i] % (a + b) == 0) ? a + b : h[i] % (a + b);
        h[i] = (h[i] - 1)/a;
    }
    sort(h+1, h+1+n);
    For(i, 1, n)
    {
        if (k - h[i] < 0) break;
        ans++;
        k -= h[i];
    } 
    cout << ans << "\n";
}

void input()
{
    cin >> n >> a >> b >> k;
    For(i, 1, n)
    cin >> h[i];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    input();
    process();
}