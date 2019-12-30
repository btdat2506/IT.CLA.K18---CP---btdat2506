#include <bits/stdc++.h>

using namespace std;

typedef int ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

char pos[5010];
ll m, n, l, ans;
bool island[510][510], f[510][510][5000];

void process()
{
    For(i, 1, m)
    For(j, 1, n)
    if (island[i][j]) f[i][j][0] = 1;
    For(i, 1, m)
    For(j, 1, n)
    For(t, 1, l)
    if (island[i][j])
    {
        if (pos[i] == '?')
            f[i][j][t] = f[i][j-1][t-1] || f[i-1][j][t-1] || f[i+1][j][t-1] || f[i][j+1][t-1];
        else
        {
            ll i1 = i, j1 = j;
            if (pos[i] == 'S') i1--;
            if (pos[i] == 'N') i1++;
            if (pos[i] == 'W') j1++;
            if (pos[i] == 'E') j1--;
            f[i][j][t] = f[i1][j1][t-1];
        }
    }
    For(i, 1, m)
    For(j, 1, n)
    For(t, 1, l)
    ans += (ll) f[i][j][l];
    cout << ans << "\n";
    
}

void input()
{
    cin >> m >> n >> l;
    For(i, 1, m)
    For(j, 1, n)
    {
        char x;
        cin >> x;
        island[i][j] = (x == '.');
    }
    For(i, 1, l) cin >> pos[i];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    input();
    process();
}