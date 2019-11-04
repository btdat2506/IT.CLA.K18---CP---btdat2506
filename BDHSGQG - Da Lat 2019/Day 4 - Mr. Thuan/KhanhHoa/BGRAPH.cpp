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
#define int long long
#define pow poww

const int N = 3e5 + 5;
int n , m , mod = 998244353 , z;
vector < int > g[N];
int pow[N];
int ans[3];
int ok[N];

int add(int a , int b)
{
    return (a + b) % mod;
}

int mul(int a , int b)
{
    return (a * b) % mod;
}

bool DFS(int i , int j , int k)
{
    ans[k]++;
    ok[i] = k;
    REP(s , g[i].size())
    {
        int u = g[i][s];
        if(u != j)
        {
            if(ok[u] == k)
                z = 0;
            if(ok[u] == 0)
                DFS(u , i , 3 - k);
        }
    }
}

main()
{
    //freopen("BGRAPH.inp","r",stdin);
    cin >> n >> m;
    FOR(i , 1 , m)
    {
        int x , y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    pow[0] = 1;
    FOR(i , 1 , n)
        pow[i] = mul(pow[i - 1] , 2);
    int res = 1;
    FOR(i , 1 , n)
        if(ok[i] == 0)
        {
            z = 1;
            ans[1] = ans[2] = 0;
            DFS(i , -1 , 1);
            if(z == 1)
                res = mul(res , add(pow[ans[1]] , pow[ans[2]]));
            else
                res = 0;
        }
    cout << res << "\n";
}
