#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;
typedef pair<bool, bool> bb;

#define x first.first //vertical position
#define y first.second //horizontal position
#define t1 second.first //good people
#define t2 second.second //bad people
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, m, ver[5] = {0, -1, 1, 0, 0}, hor[5] = {0, 0, 0, -1, 1};
char db[60][60];
vector <ii> query; //good, bad people posision

bool dfs(ii v)
{
    
}

void process()
{
    For(i, 1, n)
    For(j, 1, m)
    if (db[i][j] == 'B')
    {
        For(pos, 1, 4)
        {
            if (db[i + ver[pos]][j + hor[pos]])
            {
                cout << "No" << "\n";
                return;
            }
            if (db[i + ver[pos]][j + hor[pos]] == '.')
                db[i + ver[pos]][j + hor[pos]] = '#';
        }
    }
    For(i, 1, n)
    For(j, 1, m)
    if (db[i][j] == 'B' || db[i][j] == 'G')
        query.push_back(ii(i, j));
    for(ii v: query)
    if (!dfs(v))
    {
        cout << "No" << "\n";
        return;
    }
    cout << "Yes" << "\n";
}

void input()
{
    cin >> n >> m;
    For(i, 1, n)
    For(j, 1, m)
    cin >> db[i][j];
}

void init()
{

}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    ll t;
    cin >> t;
    while (t--)
    {
        init();
        input();
        process();
    }
}