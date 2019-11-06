#include <bits/stdc++.h>
//ý tưởng bài này là dùng dãy con tăng dần dài nhất để xác định thứ tự từ trái sang phải
using namespace std;

#define idx first
#define turn second
#define For(i, a, b) for(ll i = a; i <= b; i++)

typedef int64_t ll;

ll n, res, delay, a[100010], endof[100010], d[100010];

void process()
{
    For(i, 1, n) endof[i] = INT64_MAX;
    endof[0] = INT64_MIN;
    For(i, 1, n)
    {
        ll x = lower_bound(endof, endof+n, a[i]) - endof;
        endof[x] = a[i];
        d[i] = x;
    }
    For(i, 1, n)
    cout << d[i] * delay + a[i] << "\n";
}

void input()
{
    cin >> n >> delay;
    For(i, 1, n)
    cin >> a[i];
}

int main()
{
    freopen("RIGHT.INP", "r", stdin);
    freopen("RIGHT.OUT", "w", stdout);
    input();
    process();
}