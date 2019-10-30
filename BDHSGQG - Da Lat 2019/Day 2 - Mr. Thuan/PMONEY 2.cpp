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

const int N = 1e6 + 5;
int prefix[N];
char f[N] , ff[N];
stack < ii > q;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    //freopen("PMONEY.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    scanf("%s" , f);
    int n = strlen(f);
    FORD(i , n , 1)
        f[i] = f[i - 1];

    /*FOR(i , 1 , n)
    {
        if(f[i] == '+' || f[i] == '_')
            prefix[i] = prefix[i - 1] + 1;
        else if(f[i] == '-')
            prefix[i] = prefix[i - 1] - 1;
        else
            prefix[i] = prefix[i - 1];
        //cout << i << " " << prefix[i] << " " << f[i] << endl;
        if(prefix[i] < 0)
        {
            cout << "NIE";
            exit(0);
        }
    }
    //cout << prefix[n] << endl;

    int cnt = prefix[n];
    FOR(i , 1 , n)
        ff[i] = f[i];
    FORD(i , n , 1)
    {
        if(f[i] == '_')
        {
            if(cnt >= 2)
            {
                cnt -= 2;
                ff[i] = '-';
            }
            else if(cnt == 1)
            {
                cnt = 0;
                ff[i] = '0';
            }
            else
                ff[i] = '+';
        }
    }
    int Max = 0 , pos = 0;
    FOR(i , 1 , n)
    {
        if(ff[i] == '+')
            pos++;
        else if(ff[i] == '-')
            pos--;
        if(pos < 0)
        {
            cout << "NIE";
            exit(0);
        }
        Max += pos;
    }
    if(pos != 0)
    {
        cout << "NIE";
        exit(0);
    }*/


    /// Min
    FOR(i , 1 , n)
    {
        if(f[i] == '-' || f[i] == '_')
            prefix[i] = prefix[i - 1] - 1;
        else if(f[i] == '+')
            prefix[i] = prefix[i - 1] + 1;
        else
            prefix[i] = prefix[i - 1];
    }

    FOR(i , 1 , n)
        ff[i] = f[i];
    ll cnt = 0;

    FOR(i , 1 , n)
    {
        if(f[i] == '_')
        {
            ff[i] = '-';
            q.push(ii(i , 2));
        }
        while(prefix[i] + cnt < 0)
        {
            int val = q.t.se;
            int pos = q.t.fi;
            q.pop();
            if(prefix[i] + cnt + val > 0)
            {
                q.push(ii(pos , 1));
                cnt++;
                ff[pos] = '0';
            }
            else
            {
                ff[pos] = '+';
                cnt += val;
            }
        }
    }

    int Min = 0;
    ll pos = 0;
    FOR(i , 1 , n)
    {
        if(ff[i] == '+')
            pos++;
        else if(ff[i] == '-')
            pos--;
        Min += pos;
    }
    cout << Min << " " << "\n";
    return 0;
}
