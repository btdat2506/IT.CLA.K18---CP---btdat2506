#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, m, ans;
string S, T;

void process()
{
    n = S.size(), m = T.size();
    S = ' ' + S;
    T = ' ' + T;
    For(i, 1, n - m + 1)
    {
        ll res = 0;
        For(j, 1, m)
        if (S[i + j - 1] == T[j])
            res++;
        ans = max(ans, res);
    }
    cout << m - ans << "\n";
}

void input()
{
    cin >> S >> T;
}

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    input();
    process();
}