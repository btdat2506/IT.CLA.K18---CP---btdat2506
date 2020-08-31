#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

// begin: 22:20:05 Aug/30/2020
// end: 22:26

ll n, m;
bool valid;
string st;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        map <char, ll> cnt;
        valid = 1;
        For(i, 1, n)
        {
            cin >> st;
            m = st.size();
            st = ' ' + st;
            For(i, 1, m)
            cnt[st[i]]++;
        }
        for(map <char, ll>::iterator iter = cnt.begin(); iter != cnt.end(); iter++)
        if (iter->second % n != 0) valid = 0;
        if (valid)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
}