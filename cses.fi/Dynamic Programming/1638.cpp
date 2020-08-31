#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

const ll MOD = 1e9 + 7;
ll n, f[1010][1010];
bool db[1010][1010];

void process()
{
    if (!db[1][1]) f[1][1] = 1;
    For(i, 1, n)
    For(j, 1, n)
    if (!db[i][j])
    {
        if (!db[i-1][j]) (f[i][j] += f[i-1][j]) %= MOD;
        if (!db[i][j-1]) (f[i][j] += f[i][j-1]) %= MOD;
    }
    cout << f[n][n] % MOD << "\n";
}

void input()
{
    cin >> n;
    char ch;
    For(i, 1, n)
    For(j, 1, n)
    {
        cin >> ch;
        if (ch == '*') db[i][j] = 1;
    }
}

int main()
{
    /* freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout); */
    input();
    process();
}