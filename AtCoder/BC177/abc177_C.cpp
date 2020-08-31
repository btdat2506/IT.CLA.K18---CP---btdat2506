#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

const ll MOD = 1e9 + 7;
ll n, sum, res, arr[200010];

void process()
{
    For(i, 1, n)
    sum += arr[i];
    For(i, 1, n)
    {
        sum -= arr[i];
        res = (res + (arr[i] * (sum % MOD)) % MOD) % MOD;
    }
    cout << res << "\n";
}

void input()
{
    cin >> n;
    For(i, 1, n)
    cin >> arr[i];
}

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    input();
    process();
}