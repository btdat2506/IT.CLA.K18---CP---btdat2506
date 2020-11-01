#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

//start 7:41am Oct 7th 2020

ll n, arr[30010], ft[30010]; //fenwick tree

void compressArray()
{
    ll tmp[30010];
    memset(tmp, 0, sizeof(tmp));
    For(i, 1, n) tmp[i] = arr[i];
    sort(tmp+1, tmp+1+n);
    For(i, 1, n)
    arr[i] = lower_bound(tmp+1, tmp+1+n, arr[i]) - tmp;
}

ll query(ll idx)
{
    ll ans = 0;
    while (idx > 0)
    {
        ans = max(ans, ft[idx]);
        idx -= (idx & (-idx));
    }
    return ans; 
}

void update(ll idx)
{
    ll x = query(idx - 1),
       val = x + 1;
    while (idx <= n)
    {
        ft[idx] = max(ft[idx], val);
        idx += (idx & (-idx));
    }
}

void process()
{
    compressArray();
    For(i, 1, n)
    update(arr[i]);
    cout << query(n) << "\n";
}

void input()
{
    cin >> n;
    For(i, 1, n)
    cin >> arr[i];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    input();
    process();
}