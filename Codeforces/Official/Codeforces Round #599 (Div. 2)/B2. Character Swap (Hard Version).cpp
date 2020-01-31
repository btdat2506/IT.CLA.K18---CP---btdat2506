#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, cnt[50];
char a[100], b[100];

typedef pair<ll, ll> ii;

void process()
{
    memset(cnt, 0, sizeof(cnt));
    cin >> n;
    For(i, 1, n) cin >> a[i];
    For(i, 1, n) cin >> b[i];
    For(i, 1, n)
    cnt[a[i] - 'a' + 1]++,
    cnt[b[i] - 'a' + 1]++;
    For(i, 1, n)
    if (cnt[a[i] - 'a' + 1] % 2 != 0 || cnt[b[i] - 'a' + 1] % 2 != 0)
    {
        cout << "No" << "\n";
        return;
    }
    cout << "Yes" << "\n";
    queue <ii> res;
    For(i, 1, n)
    if (a[i] != b[i])
    {
        For(j, i+1, n)
        {
            if (a[i] == a[j]) 
            {
                swap(a[j], b[i]);
                res.push(ii(j, i));
                break;
            }
            else
            if (a[i] == b[j] && a[j] != b[j])
            {
                swap(a[j], b[j]);
                swap(a[j], b[i]);
                res.push(ii(j, j));
                res.push(ii(j, i));
                break;
            }
        }
    }
    cout << res.size() << "\n";
    while (!res.empty())
    {
    	cout << res.front().first << ' ' << res.front().second << "\n";
    	res.pop();
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t;
    cin >> t;
    while (t--)
    process();
}
