#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

struct hcn
{
    ll x1 = 0, y1 = 0, x2 = 0, y2 = 0;

    bool operator < (const hcn &T)
    {
        return (x2-x1)*(y1-y2) < (T.x2-T.x1)*(T.y1-T.y2);
    }
};

const ll N = 1010;
ll n, res[N], ans;
hcn T[N];

void process()
{
    sort(T+1, T+1+n);
    For(j, 1, n-1)
    For(i, j+1, n)
    if (T[i].x1 <= T[j].x1 && T[i].x2 >= T[j].x2 && T[i].y1 >= T[j].y1 && T[i].y2 <= T[j].y2)
    {
        res[i] += res[j] + 1;
    }
    For(i, 1, n)
    ans = max(res[i], ans);
    cout << ans << "\n";
}

void input()
{
    cin >> n;
    For(i, 1, n)
    cin >> T[i].x1 >> T[i].y1 >> T[i].x2 >> T[i].y2;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    input();
    process();
}