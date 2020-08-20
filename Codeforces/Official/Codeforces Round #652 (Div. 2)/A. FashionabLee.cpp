#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

int main()
{
/*     freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout); */
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout << ((n % 2) ? "NO" : "YES") << "\n";
    }
}