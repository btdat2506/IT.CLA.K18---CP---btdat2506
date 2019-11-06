#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, m, res, zero_count, db[1000010], dist[1000010];

ll bSearch(ll idx)
{
    ll l = 1, r = idx, mid = (l + r) / 2;
    while (mid != l && mid != r)
    {
        if (dist[idx] - dist[mid] > zero_count) 
            l = mid;
        else 
            r = mid;
    }
    return mid;
}

void process()
{
    sort(db+1, db+1+m);
    For(i, 1, m)
    {
        dist[i] = dist[i-1] + (db[i] - db[i-1]);
        ll x = bSearch(i);
        if (i - x > res) res = i - x;
    }
    cout << res << "\n";
}

void input()
{
    cin >> n;
    For(i, 1, n)
    {
        ll x;
        cin >> x;
        if (x != 0)
            ++m,
            db[m] = a[i] + 1e7;
        else
            zero_count++;
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("LSEQ.INP", "r", stdin);
    freopen("LSEQ.OUT", "w", stdout);
    input();
    process();
}