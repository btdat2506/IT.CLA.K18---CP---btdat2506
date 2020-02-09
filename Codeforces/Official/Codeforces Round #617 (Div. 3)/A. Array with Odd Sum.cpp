#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, arr[2010], cnt[2010];

int main()
{
 //   freopen("test.in", "r", stdin);
   // freopen("test.ok", "w", stdout);
    ll t;
    cin >> t;
    while (t--)
    {
        memset(cnt, 0, sizeof(cnt));
        cin >> n;
        For(i, 1, n)
        {
            cin >> arr[i];
            cnt[arr[i] % 2]++;
        }
        if ((!cnt[0] && n % 2) || (cnt[0] && cnt[1]))
            cout << "YES" << "\n";
        else
        {
            cout << "NO" << "\n";
        }
    }
}