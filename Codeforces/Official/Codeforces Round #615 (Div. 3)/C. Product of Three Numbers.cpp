#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n;
vector <ll> module_of_n;

void process()
{
    For(i, 2, sqrt(n)+1)
    if (n % i == 0) 
    {
        module_of_n.push_back(i);
        module_of_n.push_back(n/i);
    }
    sort(module_of_n.begin(), module_of_n.end());
    for(ll i = 0; i < module_of_n.size(); i++)
    for(ll j = i+1; j < module_of_n.size() && ((ll) (n/i/j)) > j; j++)
    if (i != j && ((ll) (n/i/j)) != i && ((ll) (n/i/j)) != j && ((ll) (n/i/j)) > 1
    && (i * j * ((ll) (n/i/j))) == n)
    {
        cout << "YES" << "\n";
        cout << i << ' ' << j << ' ' << ((ll) (n/i/j)) << "\n";
        return;
    }
    cout << "NO" << "\n";
}

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        process();
    }
}