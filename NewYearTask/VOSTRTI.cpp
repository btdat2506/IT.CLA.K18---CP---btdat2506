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
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
ll n, dem[100010], ans = 0;
pair <ll, ll> A[100010];

bool Comparision(const pair<ll, ll> m, const pair<ll, ll> n)
{
    return (m.X < n.X) || (m.X == n.X && m.Y < n.Y);
}
int main()
{
	faster
	cin >> n;
    For(i, 1, n)
    {
        cin >> A[i].X >> A[i].Y;
        dem[A[i].Y]++;
    }
    sort(A+1, A+n+1, Comparision);
    for(ll i = 1; i <= n;)
    {
        ll j = i;
        while (A[j+1].X == A[i].X && j < n) j++;
        For(k, i, j) ans += (j - i) * (dem[A[k].Y] - 1);
        i = j + 1;
    }
    cout << ans;
    return 0;
}