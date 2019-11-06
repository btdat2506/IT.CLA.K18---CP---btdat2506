#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n;
array <array<ll, 100010>, 7> Q;
//chuyển lỗi segmentation fault về exception, có thể dùng try catch, ngoài ra luôn khởi tạo từ 0

bool cmp(const ll &L, const ll &R)
{
    ll res = 0;
    For(i, 1, 5)
    res += (Q[i][L] < Q[i][R]);
    //res = (Q[a][1] < Q[b][1]) + (Q[a][2] < Q[b][2]) + (Q[a][3] < Q[b][3]) + (Q[a][4] < Q[b][4]) + (Q[a][5] < Q[b][5]);
    return (res >= 3);
}

void process()
{
	vector <ll> a (n);
    iota(a.begin(), a.end(), 1);
    sort(a.begin(), a.end(), cmp);
    for(ll x: a)
    cout << x << ' ';
}

void input()
{
    cin >> n;
    For(i, 1, 5)
    For(j, 1, n)
    {
        ll x;
        cin >> x;
        Q[i][x] = j;
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("PHOTO.INP", "r", stdin);
    freopen("PHOTO.OUT", "w", stdout);
    input();
    process();
}
