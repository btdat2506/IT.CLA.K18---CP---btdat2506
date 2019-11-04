/// đm đừng cop code t nữa , t có súng đó.
/// đm đừng cop code t nữa , t có súng đó.
/// đm đừng cop code t nữa , t có súng đó.
/// đm đừng cop code t nữa , t có súng đó.
/// đm đừng cop code t nữa , t có súng đó.
/// đm đừng cop code t nữa , t có súng đó.
/// đm đừng cop code t nữa , t có súng đó.
/// đm đừng cop code t nữa , t có súng đó.
/// đm đừng cop code t nữa , t có súng đó.
/// đm đừng cop code t nữa , t có súng đó.
/// đm đừng cop code t nữa , t có súng đó.
/// đm đừng cop code t nữa , t có súng đó.
/// đm đừng cop code t nữa , t có súng đó.
/// đm đừng cop code t nữa , t có súng đó.
/// đm đừng cop code t nữa , t có súng đó.
/// đm đừng cop code t nữa , t có súng đó.
/// đm đừng cop code t nữa , t có súng đó.
/// đm đừng cop code t nữa , t có súng đó.
/// đm đừng cop code t nữa , t có súng đó.
/// đm đừng cop code t nữa , t có súng đó.
/// đm đừng cop code t nữa , t có súng đó.

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

const int N = 1e6 + 5;
int n , m , ssc , res;
int val[N] , par[N];
iv st[4 * N];
ii Min[4 * N][12];
ii sign[4 * N];
iii a[N];
ii p[N];
vector < ii > g[N];

bool cmp(ii a , ii b)
{
    return a.se < b.se;
}

int acs(int u)
{
    if(par[u] == u) return u;
    else return par[u] = acs(par[u]);
}

void join(int u , int v)
{
    par[acs(u)] = acs(v);
}

int mini(int id , int val , int pos)
{
    FOR(i , 1 , 8)
    {
        if(Min[id][i].fi > val)
        {
            FORD(k , 8 , i + 1)
                Min[id][k] = Min[id][k - 1];
            Min[id][i].fi = val;
            Min[id][i].se = pos;
        }
        if(Min[id][i].se == pos)
            break;
    }
}

int mini1(int id , int val , int pos)
{
    mini(id , val , pos);
    if(sign[id].fi > val)
        sign[id].fi = val , sign[id].se = pos;
}

int mini2(int id , int val , int pos)
{
    if(st[id].fi.fi > val)
        st[id].fi.fi = val , st[id].fi.se = pos;
}

int down(int id)
{
    if(sign[id].fi != oo)
    {
        mini(id * 2 , sign[id].fi , sign[id].se);
        mini(id * 2 + 1 , sign[id].fi , sign[id].se);

        mini1(id * 2 , sign[id].fi , sign[id].se);
        mini1(id * 2 + 1 , sign[id].fi , sign[id].se);
    }
}

void up(int id , int l , int r , int u , int v , int val , int pos , int type)
{
   if(l > v || r < u)
        return;
   else if(l >= u && r <= v)
   {
       if(type == 1)
            mini2(id , val , pos);
       else
       {
            mini(id , val , pos);
            mini1(id , val , pos);
       }
       return;
   }
   down(id);
   int mid = (l + r) / 2;
   up(id * 2 , l , mid , u , v , val , pos , type);
   up(id * 2 + 1 , mid + 1 , r , u , v , val , pos , type);
    FOR(i , 1 , 8)
        mini(id , Min[id * 2][i].fi , Min[id * 2][i].se);
    FOR(i , 1 , 8)
        mini(id , Min[id * 2 + 1][i].fi , Min[id * 2 + 1][i].se);
   if(st[id * 2].fi.fi <= st[id * 2 + 1].fi.fi)
        mini2(id , st[id * 2].fi.fi , st[id * 2].fi.se);
   else
        mini2(id , st[id * 2 + 1].fi.fi , st[id * 2 + 1].fi.se);
}

ii get1(int id , int l , int r , int u , int v)
{
    if(l > v || r < u)
        return ii(oo , oo);
    else if(l >= u && r <= v)
        return ii(st[id].fi.fi , st[id].fi.se);
    down(id);
    int mid = (l + r) / 2;
    return min(get1(id * 2 , l , mid , u , v) , get1(id * 2 + 1 , mid + 1 , r , u , v));
}

ii get2(int id , int l , int r , int u , int v , int pos)
{
    //cout << l << " " << r << " " << u << " " << v << " " << st[id].se << " " << id << endl;
    if(l > v || r < u)
        return ii(oo , oo);
    else if(l >= u && r <= v)
        return ii(Min[id][pos].fi , Min[id][pos].se);
    down(id);
    int mid = (l + r) / 2;
    return min(get2(id * 2 , l , mid , u , v , pos) , get2(id * 2 + 1 , mid + 1 , r , u , v , pos));
}


main()
{
    //freopen("GALAXY.inp","r",stdin);
    //freopen("GALAXY.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    if(n * m > 1e6)
    {
        FOR(i , 1 , 4 * n)
        {
            sign[i].fi = oo;
            st[i].fi.fi = st[i].se.fi = oo;
        }
        FOR(i , 1 , 4 * n)
            FOR(j , 1 , 8)
                Min[i][j].fi = Min[i][j].se = oo;

        FOR(i , 1 , n)
        {
            cin >> val[i];
            up(1 , 1 , n , i , i , val[i] , i , 1);
        }
        FOR(i , 1 , m)
        {
            int x , y , z;
            cin >> x >> y >> z;
            g[x].pb(ii(y , z));
        }
        FOR(i , 1 , n)
        {
            int pos = i;
            REP(s , g[pos].size())
            {
                int l = g[pos][s].fi;
                int r = g[pos][s].se;
                ii x = get1(1 , 1 , n , l , r);
                up(1 , 1 , n , pos , pos , x.fi , x.se , 2);
                up(1 , 1 , n , l , r , val[pos] , pos , 2);
            }
        }
        int r = 0;
        ssc = n;
        FOR(i , 1 , n)
        {
            int pos = i;
            FOR(j , 1 , 8)
            {
                ii x = get2(1 , 1 , n , pos , pos , j);
                if(x.se <= n)
                    a[++r] = iii(x.fi + val[pos] , ii(x.se , pos));
            }
        }
        FOR(i , 1 , n)
            par[i] = i;
        sort(a + 1 , a + 1 + r);
        FOR(i , 1 , r)
        {
            int x = a[i].se.fi;
            int k = a[i].se.se;
            if(acs(x) != acs(k))
            {
                join(x , k);
                res += a[i].fi;
                ssc--;
                if(ssc == 1)
                {
                    cout << res;
                    exit(0);
                }
            }
        }
    }
    else
    {
        FOR(i , 1 , n)
            cin >> val[i];
        int ssc = n;
        FOR(i , 1 , n)
            par[i] = i;
        int r = 0;
        FOR(i , 1 , m)
        {
            int x , y , z;
            cin >> z >> x >> y;
            FOR(i , x , y)
                a[++r] = iii(val[z] + val[i] , ii(z , i));
        }
        sort(a + 1 , a + 1 + r);
        FOR(i , 1 , r)
        {
            int x = a[i].se.fi;
            int k = a[i].se.se;
            if(acs(x) != acs(k))
            {
                join(x , k);
                res += (val[x] + val[k]);
                ssc--;
                if(ssc == 1)
                {
                    cout << res;
                    exit(0);
                }
            }
        }
    }
}

