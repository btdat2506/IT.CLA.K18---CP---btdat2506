#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

void test()
{
    For(i, 1, 100)
    {
        bool t = 0;
        for(ll k3 = 0; k3 <= 100 && !t; k3++)
        for(ll k5 = 0; k5 <= 100 && !t; k5++)
        for(ll k7 = 0; k7 <= 100 && !t; k7++)
            if (k3 * 3 + k5 * 5 + k7 * 7 == i)
            {
                cout << k3 << ' ' << k5 << ' ' << k7 << "\n";
                t = 1; 
            } 
        if (!t) cout << -1 << "\n";   
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    //test();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        bool t = 0;
        cin >> n;
        for(ll i = 0; i <= n && !t; i++)
        for(ll j = 0; j <= n && !t; j++)
        {
            if (n - i*3 - j*5 >= 0 && (n - i*3 - j*5) % 7 == 0)
            {
                t = 1;
                cout << i << ' ' << j << ' ' << (n - i*3 - j*5) / 7 << "\n";
            }
        }
        if (t == 0)
            cout << -1 << "\n";
    }
}   