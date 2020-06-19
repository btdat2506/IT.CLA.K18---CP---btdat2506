#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, x, sum, ans, arr[100010];

void process()
{
    sum = 0;
    For(i, 1, n)
    sum += arr[i];
    if (sum % x != 0) 
        ans = n;
    else
    {
        ll a = 1, b = n;
        while (arr[b] % x == 0 && b >= 1) b--;
        while (arr[a] % x == 0 && a <= n) a++;
        ans = (n - a > b - 1) ? n - a : b - 1;
    }
    cout << ans << "\n";
}

void input()
{
    cin >> n >> x;
    For(i, 1, n)
    cin >> arr[i];
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