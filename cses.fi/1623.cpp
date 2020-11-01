#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i < b; i++)

ll n, res1, res2, ans = 1e10, arr[30];

bool ckBit(ll t, ll i)
{
    return ((t >> i) & 1) == 1;
}

void process()
{
    For(t, 0, (1 << n))
    {
        res1 = res2 = 0;
        For(i, 0, n)
        if (ckBit(t, i))
            res1 += arr[i];
        else
            res2 += arr[i];
        ans = min(ans, abs(res1 - res2));
    }
    cout << ans << "\n";
}

void input()
{
    cin >> n;
    For(i, 0, n)
    cin >> arr[i];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    /* freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout); */
    input();
    process();
}