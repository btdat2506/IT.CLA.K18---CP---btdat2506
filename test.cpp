#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, f[110], t[1000];

void process()
{
    f[1] = 1;
    For(i, 2, 100)
    f[i] = (f[i-1] + f[i-2]) % 100;
    For(i, 1, 100)
    cout << f[i] % 100 << " ";
}

void input()
{
    
}

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    input();
    process();
}