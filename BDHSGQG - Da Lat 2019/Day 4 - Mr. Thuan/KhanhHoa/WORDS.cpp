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

const int N = 1e2 + 5;
int n , res , q;
int a[N][N];
unordered_map < string , int > m;
unordered_set < string > ss;
char f[N];
string s;

main()
{
    //freopen("WORDS.inp","r",stdin);
    //freopen("WORDS.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    FOR(i , 1 , n)
        FOR(j , 1 , n)
            cin >> a[i][j];
    FOR(k , 1 , n)
    {
        FOR(i , 1 , n)
        {
            s.clear();
            FOR(j , i , min(n , (i + 49)))
            {
                if(a[k][j] == 1)
                    s.pb('1');
                else
                    s.pb('0');
                m[s]++;
            }
        }
    }
    cin >> q;
    while(q--)
    {
        string s;
        cin >> s;
        if(ss.find(s) == ss.end())
        {
            ss.insert(s);
            res += m[s];
        }
    }
    cout << res << "\n";
}
