#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll m; //thời gian tối đa nếu giữ nhân công sẽ lỗ
ll n, h, s, d, ans, f[100010];
ll k[100010], st[400010]; //số lượng nhân công

ll get(ll id, ll l, ll r, ll u, ll v)
{
    if (v < l || r < u)
        return -1e9;

    if (l >= u && r <= v)
        return st[id];
    
    ll mid = (l + r) / 2;
    return max(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

void build(ll id, ll l, ll r)
{
    if (l == r)
    {
        st[id] = k[l];
        return;
    }

    ll mid = (l + r) / 2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);

    st[id] = max(st[id*2], st[id*2+1]);
}

void process()
{
    ll cnt = 0;
    m = (h + d) / s;
    build(1, 1, n+1);
    For(i, 1, n)
    {
        if (k[i] > k[i-1])
        ans += (k[i] - k[i-1]) * h;
        
        ans += s * k[i];
        cnt = get(1, 1, n + 1, i + 1, min(i + m + 1, n + 1));
        
        if (cnt < k[i]) 
            ans += (k[i] - cnt) * d,
            k[i + 1] = cnt;
        else
        {
            if (k[i+1] <= k[i]) k[i + 1] = k[i];
        }
        
    }
    cout << ans << "\n";
    For(i, 1, n)
    cout << k[i] << ' ';
}

void input()
{
    cin >> n >> h >> s >> d;
    For(i, 1, n)
    cin >> k[i];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("PROJECT.INP", "r", stdin);
    freopen("PROJECT.OUT", "w", stdout);
    input();
    process();
}