#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, m, k, c[200][200], d[200];

bool findpath(ll source, ll target)
{
    queue <ll> qu;
    For(i, 1, n)
        d[i] = 0;
    d[source] = 1e11;
    qu.push(source);
    while (!qu.empty())
    {
        ll u = qu.front(); qu.pop();
        if (u == target)
            return true;
        For(i, 1, m)
        {
            
        }
    }
}

void enlarge()
{

}

void process()
{
    ll source = n + 1, target = n + 2;
    For(i, 1, n)
    c[source][i] = 1e11,
    c[i][target] = 1e11;
    //matching using max flow algo
    while (findpath(source, target))
        enlarge();
    
}

void input()
{
    cin >> n >> m;
    For(i, 1, n)
    For(j, 1, m)
    cin >> c[i][j];
    cin >> k;
}

int main()
{
    freopen("ATHLETE.INP", "r", stdin);
    freopen("ATHLETE.OUT", "w", stdout);
    input();
    process();
}