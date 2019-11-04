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

const int N = 1e4 + 5;
int n , M;
ll res , mod = 1e9 + 7;
int a[N] , val[N] , cnt[N];

main()
{
    //freopen("TRIPLE.inp","r",stdin);
    //freopen("TRIPLE.out","w",stdout);
    scanf("%d %d" , &n , &M);
    FOR(i , 1 , n)
        scanf("%d" , &a[i]);
    sort(a + 1 , a + 1 + n);
    FOR(i , 3 , n)
        val[i] = M - a[i];
    FOR(i , 2 , n)
    {
        res += cnt[i];
        int r = n;
        int start = 1;
        int j = 1;
        while(j <= i - 1)
        {
            start = j;
            int ans = 1;
            while(j < i - 1 && a[j] == a[j + 1])
            {
                j++;
                ans++;
            }
            while(r >= i && val[r] <= a[i] + a[j])
            {
                if(val[r] == a[i] + a[j])
                    cnt[r] += ans;
                r--;
            }
            j++;
        }
    }
    printf("%d" , res % mod);
}
