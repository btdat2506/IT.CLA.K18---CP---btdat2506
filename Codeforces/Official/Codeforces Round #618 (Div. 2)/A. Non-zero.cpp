#include <bits/stdc++.h>

using namespace std;

//begin: 21:41 Feb 09 Sunday
//end: 

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, ans, sum, arr[1000];

void process()
{
    ans = sum = 0;
    For(i, 1, n)
    {
        if (arr[i] == 0)
            arr[i] = 1,
            ans++;
        sum += arr[i];
    }
    if (sum == 0)
        cout << ans + 1 << "\n";
    else
        cout << ans << "\n";
}

void input()
{
    cin >> n;
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