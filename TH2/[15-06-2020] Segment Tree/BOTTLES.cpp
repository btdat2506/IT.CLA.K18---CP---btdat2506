#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

struct dt
{
    ll val = 0;
    queue <ll> pos;
};

dt minn(dt L, dt R)
{
    if (L.val < R.val)
    return L; return R;
}

ll n, k, res, a[100010];
dt st[400010], f[100010];

void update(ll id, ll l, ll r, ll i, dt val)
{
    if (i < l || i > r)
        return;
    
    if (l == r)
    {
        st[id] = val;
        return;
    }

    ll mid = (l + r) / 2;
    update(id*2, l, mid, i, val);
    update(id*2 + 1, mid + 1, r, i, val);

    st[id] = minn(st[id*2], st[id*2 + 1]);
}

dt get(ll id, ll l, ll r, ll u, ll v)
{
    if (v < l || u > r)
        return {(ll) 1e9, queue <ll> {}};
    
    if (l >= u && v >= r)
        return st[id];
    
    ll mid = (l + r) / 2;
    return minn(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

void process()
{
    For(i, 0, 4*n+10) st[i].val = 1e9;
    For(i, 1, n + 1)
    {
        if (i <= k)
        {
            f[i].val = a[i];
            f[i].pos.push(i);
            update(1, 1, n, i, f[i]);
        }
        else
        {
            f[i] = get(1, 1, n, i-k, i-1);
            f[i].val += a[i];
            f[i].pos.push(i);
            update(1, 1, n, i, f[i]);
        }
    }
    cout << n - f[n+1].pos.size() << ' ' << res - f[n+1].val << "\n";
    For(i, 1, n)
    {
        if (i == f[n+1].pos.front())
            f[n+1].pos.pop();
        else
        {
            cout << a[i] << " ";
        }
    }
}

void input()
{
    cin >> n >> k;
    For(i, 1, n)
    {
        cin >> a[i];
        res += a[i];
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("BOTTLES.INP", "r", stdin);
    freopen("BOTTLES.OUT", "w", stdout);
    input();
    process();
}
