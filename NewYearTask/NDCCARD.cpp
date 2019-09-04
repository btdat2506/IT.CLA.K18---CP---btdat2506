#include <bits/stdc++.h>

typedef unsigned long long ull;

using namespace std;
#define For(i, a ,b) for(int64_t i = a; i <= b; i++)
#define FOD(i,r,l) for (int64_t i=r;i>=l;i--)
#define ll int64_t
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define ep emplace_back
#define EL cout << endl;
#define sz(A) (int) A.size()
#define fillchar(a,x) memset(a, x, sizeof (a))
#define read(a) cin >> a;
#define writeln(a) cout << a << endl;
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

ll n, m, a[20000], temp[10], ans = 0;


ll bSearch(ll l, ll r, ll x)
{
    ll mid = (l + r) / 2;
    if (l >= r) 
    if (a[l] <= x) return l; else return l-1;
    if (a[mid] > x) return bSearch(l, mid - 1, x);
    return bSearch(mid + 1, r, x);
}

int main()
{
    cin >> n >> m;
    For(i, 1, n) cin >> a[i];
    sort(a+1, a+n+1);
    For(i, 1, n-1)
    For(j, i+1, n)
    {
        ll k = bSearch(1, n, m - a[i] - a[j]);
        if (m >= (a[i] + a[j] + a[k]) && i != k && j != k) ans = max(ans, a[i] + a[j] + a[k]);
        else break;
    }
    cout << ans << endl;
}