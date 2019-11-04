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
#define t top()

#define FOR(i , x , n) for(int i = x ; i <= n ; ++i)
#define REP(i , n) for(int i = 0 ; i < n ; ++i)
#define FORD(i , x , n) for(int i = x ; i >= n ; --i)

#define ll long long
#define oo 1e17

const int N = 4e5 + 5;
const int VAL = 4e6 + 50;
int mod , base , Max , x , y , z;
int poww[N] , sum[N] , dp[N];
char f[N] , ff[N];
int m[VAL];
vector < int > ans;

int get(int l , int r)
{
    return (sum[r] - sum[l - 1] * poww[r - l + 1]);
}

int get1(int l , int r)
{
    return (dp[r] - dp[l - 1] * poww[r - l + 1]);
}

main()
{
    //freopen("STRkARY.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    scanf("%s" , f);
    int n = strlen(f);
    base = 31;
    mod = 4e6 + 37;
    poww[0] = 1;
    FOR(i , 1 , n)
        poww[i] = poww[i - 1] * base;
    dp[0] = f[0] - 'a' + 1;
    FOR(i , 1 , n - 1)
        dp[i] = dp[i - 1] * base + f[i] - 'a' + 1;

    bool ok = true;
    ans.pb(1);
    FORD(i , n - 1 , 2)
    {
        if(f[i] != f[i - 1])
            ok = false;
        if(n % i == 0)
        {
            int r = 0;
            FOR(k , 0 , i - 1)
                ff[++r] = f[k];
            FOR(j , r + 1 , 2 * r)
                ff[j] = ff[j - r];

            FOR(j , 1 , 2 * r)
                sum[j] = (sum[j - 1] * base + ff[j] - 'a' + 1);
            FOR(k , 1 , i)
                m[(get(k , k + i - 1) % mod + mod) % mod]++;


            int z = n / i - 1;
            FORD(j , z , 1)
            {
                int r = 0;
                if(m[(get1(j * i , (j + 1) * i - 1) % mod + mod) % mod] == 0)
                    goto l1;
            }
            FOR(k , 1 , i)
                m[(get(k , k + i - 1) % mod + mod) % mod] = 0;
            ans.pb(n / i);
        }
        l1:;
    }
    if(ok && f[0] == f[1])
        ans.pb(n);
    printf("%d\n" , ans.size());
    REP(s , ans.size())
        printf("%d " , ans[s]);
}
