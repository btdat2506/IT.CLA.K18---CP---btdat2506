#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, k, a[100010];

void process()
{
    sort(a+1, a+1+n);
    ll l = 1, r = n, mid = (l + r) / 2;
    while (l != mid && r != mid)
    {
        ll curr = 1, leng = 1;
        For(i, 2, n)
        {
            if (a[i] - a[i-1] > mid)
                curr = 1;
            else
                curr++;
            leng = max(leng, curr);            
        }
        if (n - leng <= k)
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << "\n";
}

void input()
{   
    cin >> n >> k;
    For(i, 1, n) cin >> a[i];
}

int main()
{
    freopen("MAXDIFF.INP", "r", stdin);
    freopen("MAXDIFF.OUT", "w", stdout);
    input();
    process();
}