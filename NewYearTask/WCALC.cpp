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

ll b, n, ans = 0; 


bool check(ll m)
{
    return (b * m * (2 * n - m) % (n * n)) == 0;
}

int main()
{
    cin >> b >> n;
    For(i, 1, n*2-1) if (check(i)) ans++;
    cout << ans;
    return 0;
}