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

const int N = 2e6 + 5;
int n , q , mod = 1e9 + 7;
int fact[N];
char f[N];

int add(int a , int b)
{
    return (a + b) % mod;
}

int mul(int a , int b)
{
    return (a * b) % mod;
}

int sub(int a , int b)
{
    return ((a - b) % mod + mod) % mod;
}

int powmod(int a , int b)
{
    int res = 1;
    while(b)
    {
        if(b & 1)
            res = mul(res , a);
        a = mul(a , a);
        b >>= 1;
    }
    return res;
}

int C(int n , int k)
{
    return (mul(fact[n] , powmod(mul(fact[k] , fact[n - k]) , mod - 2)));
}

int Calc(int n , int m)
{
    return mul(m + 1 , mul(C(n + 1 , (n - m) / 2) , powmod(n + 1 , mod - 2)));
}

main()
{
    //freopen("BRORDER.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;
    fact[0] = 1;
    FOR(i , 1 , 2e6)
        fact[i] = mul(fact[i - 1] , i);
    while(q--)
    {
        int res = 1;
        int x = 0;
        cin >> f;
        int n = strlen(f);
        FORD(i , n , 1)
            f[i] = f[i - 1];
        int cnt = 0;
        FOR(i , 1 , n)
        {
            if(f[i] == '(')
                cnt++;
            else
            {
                res = add(res , Calc(n - i , cnt + 1));
                cnt--;
            }
        }
        cout << res << "\n";
    }
}
