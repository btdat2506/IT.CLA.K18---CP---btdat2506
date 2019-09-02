#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i < b; i++)

int main()
{
    ll test = 0;
    ll x;
    while (cin >> x)
    {
        ll dem = 0;
        For(i, 1, x+1)
        For(j, 1, x+1)
        {
            if (abs(i - j) * (i + j + 1) == 2 * x && (abs(i - j) * (i + j + 1)) % 2 == 0) dem++;
        }
        cout << ceil(dem/2) << endl;
    }
}