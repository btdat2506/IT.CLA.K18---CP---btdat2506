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

const int N = 1e3 + 5;
int n , m , qq;
int w[N] , a[N] , cnt[N];
vector < int > g[N];

main()
{
    //freopen("DOG.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    FOR(i , 1 , n)
        cin >> w[i];
    cin >> m;
    FOR(i , 1 , m)
    {
        int u , v;
        cin >> u >> v;
        g[u].pb(v);
    }
    cin >> qq;
    a[1] = w[1];
    FOR(i , 0 , qq)
    {
        FOR(j , 1 , n)
            if(a[j] != 0)
                a[j]++;
        FOR(j , 1 , n)
        {
            if(a[j] == w[j] + 1)
            {
                cnt[j]++;
                REP(s , g[j].size())
                {
                    int u = g[j][s];
                    if(a[u] == 0)
                        a[u]++;
                }
            }
        }
        FOR(j , 1 , n)
            if(a[j] == w[j] + 1)
                a[j] = 0;
    }
    FOR(i , 1 , n)
        cout << cnt[i] << "\n";
}
