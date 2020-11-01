#include <bits/stdc++.h>

//begin: 21:07
//end: 21:49

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, q, ans;
char query[100010];
bool removed[100010];
set <ll> ch[32];

void process()
{
    For(i, 1, q)
    {
        ll res = query[i] - 'a' + 1;
        if (removed[res])
        {
            cout << n << "\n";
            continue;
        }
        else
        {
            cout << (n -= ch[res].size()) << "\n";
            removed[res] = 1;
            for(ll v: ch[res])
            {
                For(i, 1, 30)
                if (!removed[i]) ch[i].erase(v);
            }
        }
    }
}

void input()
{
    string st;
    cin >> n >> q;
    For(i, 1, n)
    {
        cin >> st;
        For(j, 0, st.length()-1)
        ch[st[j] - 'a' + 1].insert(i);
    }
    For(i, 1, q)
    cin >> query[i];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    input();
    process();
}