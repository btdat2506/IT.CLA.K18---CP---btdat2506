#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, leng;

void process()
{
    while (ll tmp = n)
    {
        leng++;
        tmp /= 10;
    }
    For(i, 1, leng)
    {
        ans += ans*10;
    }
}

void input()
{
    cin >> n;
}

int main()
{
    freopen("VITINH.INP", "r", stdin);
    freopen("VITINH.OUT", "w", stdout);
    input();
    process();
}