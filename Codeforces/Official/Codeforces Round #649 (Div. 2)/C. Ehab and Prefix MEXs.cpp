#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

bool ex[100010];
ll n, a[100010], b[100010];

void process()
{
    memset(b, -1, sizeof(b));
    memset(ex, 0, sizeof(ex));
    For(i, 1, n)
    if (a[i] != a[i-1])
    {
        b[i] = a[i-1];
        ex[b[i]] = 1;
    }
    ex[a[n]] = 1;
    ll m = 0;
    For(i, 1, n)
    {
        while (ex[m]) m++;
        if (b[i] == -1)
        {
            b[i] = m;
            ex[m] = 1;
        }
        cout << b[i] << ' ';
    }   
}

void input()
{
    cin >> n;
    For(i, 1, n)
    cin >> a[i];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    input();
    process();
}