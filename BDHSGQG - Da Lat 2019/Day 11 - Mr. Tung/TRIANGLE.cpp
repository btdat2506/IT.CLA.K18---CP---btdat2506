#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll a[4], res;

int main()
{
    freopen("TRIANGLE.INP", "r", stdin);
    freopen("TRIANGLE.OUT", "w", stdout);
    cin >> a[1] >> a[2] >> a[3];
    sort(a+1, a+4, greater<ll>());
    if (a[2] + a[3] <= a[1])
    res = a[1] - a[2] - a[3];
    cout << ++res << '\n';
}