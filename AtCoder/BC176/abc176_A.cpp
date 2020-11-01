#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

// begin: 14:20:10 Sep/07/2020
// end: 

ll n, t, x;

void process()
{
    cout << n / x * t << "\n";
}

void input()
{
    cin >> n >> x >> t;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    input();
    process();
}