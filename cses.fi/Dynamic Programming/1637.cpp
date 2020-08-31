#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n;

void process()
{
    vector <ll> dp (n + 10, 1e12);
    dp[0] = 0;
    For(i, 1, n)
    for(char v: to_string(i))
        dp[i] = min(dp[i], dp[i - (v - '0')] + 1);
    cout << dp[n] << "\n";
}

void input()
{
    cin >> n;
}

int main()
{
    /* freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout); */
    input();
    process();
}