#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll a, b, n, res = 1;

void process()
{
    n = a + b;
    For(i, 1, min(a, b))
        res *= n - i + 1,
        res /= i;
    cout << res << "\n";
}

void input()
{
    cin >> a >> b;
}

int main()
{
    freopen("NKPATH.INP", "r", stdin);
    freopen("NKPATH.OUT", "w", stdout);
    input();
    process();
}