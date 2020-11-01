#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

// begin: 08:25:43 Sep/09/2020
// end: 

ll n, db[20][20], f[20][140000];

bool getBit(ll t, ll pos)
{
    return t && (1 << pos);
}

void process()
{
    For(i, 1, n)
    For(j, 1, 1 << n)
    {

    }
}

void input()
{
    cin >> n;
    For(i, 1, n)
    For(j, 1, n)
    cin >> db[i][j];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    input();
    process();
}