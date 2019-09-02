#include <bits/stdc++.h>

using namespace std;

#define For(i, a, b) for(int i = a; i <= b; i++)
#define Fod(i, a, b) for(int i = a; i >= b; i--)
#define ll int64_t

int n, p[20] = {}, w, b[101] = {0, 1, 1, 2, 2, 1, 2, 2, 3, 3, 1, 2, 2, 3, 3, 1, 2, 2, 3, 3}, sum[101] = {}; ll ans = INT64_MAX;

void input()
{
    freopen("DUMBBELL.INP", "r", stdin);
    freopen("DUMBBELL.OUT", "w", stdout);
    cin >> n;
    For(i, 1, n) cin >> p[i];
    cin >> w;
}

void process()
{
    //For(i, 20, 100) b[i] = (int) i/20 + b[i%20];
    sum[1] = p[1];
    For(i, 2, n) sum[i] = p[i] + sum[i-1];
    Fod(i, n, 1)
    if (w - sum[i-1] >= 0)
    {
        ll t = w - sum[i-1], res = t/20 + b[i%20] + n - i + 1;
        ans = min(ans, res);
    }
    cout << ans << endl;
}

int main()
{
    input();
    process();    
}