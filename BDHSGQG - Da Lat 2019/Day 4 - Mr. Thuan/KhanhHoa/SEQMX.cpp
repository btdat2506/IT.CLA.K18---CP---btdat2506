#include<bits/stdc++.h>
using namespace std;

#define y1 as214
#define ii pair < int , int >
#define iii pair < int , ii >
#define iv pair < ii , ii >

#define fi first
#define se second
#define fr front()
#define pb push_back


#define FOR(i , x , n) for(ll i = x ; i <= n ; ++i)
#define REP(i , n) for(ll i = 0 ; i < n ; ++i)
#define FORD(i , x , n) for(ll i = x ; i >= n ; --i)

#define ll long long
#define oo 1e17
#define int long long
#define eps 1e-8

const int N = 1e5 + 5;
int n , k;
double a[N] , b[N] , dp[N] , sum[N];

bool ok(double mid)
{
    double res = -oo;
    FOR(i , 1 , n)
        b[i] = a[i] - mid;
    FOR(i , 1 , n)
    {
        dp[i] = max(dp[i - 1] + b[i] , b[i]);
        sum[i] = sum[i - 1] + b[i];
    }
    FOR(i , k , n)
    {
        res = max(res , max((double)0 , dp[i - k]) + sum[i] - sum[i - k]);
        if(res >= 0)
            return true;
    }
    return false;
}

main()
{
    //freopen("SEQMX.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    FOR(i , 1 , n)
        cin >> a[i];
    double l = -1e5 , r = 1e5 , res = -1e5;
    while((r - l) >= eps)
    {
        double mid = (double)(l + r) / 2;
        if(ok(mid))
            res = mid , l = mid + eps;
        else
            r = mid - eps;
    }
    cout << setprecision(5) << fixed << res;
}
