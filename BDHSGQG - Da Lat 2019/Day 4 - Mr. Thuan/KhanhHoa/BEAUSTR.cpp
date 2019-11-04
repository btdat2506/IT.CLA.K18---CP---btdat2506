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

const int N = 5e5 + 5;
int n , res;
int prefix[N] , P[N] , PP[N] , suffix[N];
vector < int > g;
char f[N];

main()
{
    //freopen("BEAUSTR.inp","r",stdin);
    //freopen("BEAUSTR.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    scanf("%d" , &n);
    g.pb(0);
    FOR(i , 1 , n)
    {
        scanf(" %c" , &f[i]);
        prefix[i] = prefix[i - 1] + (f[i] == '0');
    }
    FORD(i , n , 1)
    {
        suffix[i] = suffix[i + 1] + (f[i] == '0');
        if(f[i] == '0')
        {
            P[suffix[i]] = i;
            PP[i] = PP[i + 1];
        }
        else if(f[i] == '1')
            PP[i] = i;
    }

    int res = n - suffix[1];
    FOR(i , 1 , n)
    {
        int pos = 1;
        int cnt = 0;
        while(true)
        {
            pos = PP[P[suffix[pos] - i + 1]];
            if(pos == 0 || suffix[pos] < i)
                break;
            else
                cnt++;
        }
        if(cnt != 0)
            res = max(res , cnt + (cnt + 1) * i);
    }
    cout << res << "\n";
}
