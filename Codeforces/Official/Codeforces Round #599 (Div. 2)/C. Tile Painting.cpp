#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

ll n, res, ans = 1;

void process()
{
    if (n == 2 || n == 3)
    {
        cout << n << "\n";
        return;
    }
    For(i, 2, sqrt(n))
    if (n % i == 0)
    {
        res++;
        ans = i;
        while (n % i == 0) n /= i;
    }
    if (n > 1) 
    {
        res++;
        ans = n;
    }
    if (res == 1) 
        cout << ans << "\n";
    else
        cout << 1 << "\n";
    
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    process();
}