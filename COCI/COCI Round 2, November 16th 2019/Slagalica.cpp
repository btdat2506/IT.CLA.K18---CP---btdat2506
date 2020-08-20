#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;
#define For(i, a, b) for(ll i = a; i <= b; i++)

vector <ll> res;
vector <ii> leftt, rightt;
ll n, le, ri, cnt1, cnt4, right_end, t[100010];
bool visited[100010];

bool isValid()
{
    if (le && ri && cnt4 != cnt1 + 1) return 0;
    if (!le && !ri && cnt1 != cnt4 + 1) return 0;
    if (le ^ ri && cnt1 != cnt4) return 0;
    if (le ^ ri && cnt1 == 0)
    {
        if (le && leftt.size()) return 0;
        if (ri && rightt.size()) return 0;
    }
    return 1;
}   

void process()
{
    bool le = (t[1] == 5) ? true : false,
         ri = (t[n] == 7) ? true : false;
    if (!isValid())
    {
        cout << -1 << '\n';
        return;
    }
    sort(leftt.begin(), leftt.end());
    sort(rightt.begin(), rightt.end());
    ll last_changes = 0,
       need_room = !le;
    vector <ii>::iterator l = leftt.begin(), 
                          r = rightt.begin();
    while (!((l == leftt.end() && need_room) || r == rightt.end() && !need_room))
    {
        if (need_room)
        {
            if (l -> second == 1)
            {
                need_room = 0;
                last_changes = res.size() - 1;
            }
            res.push_back(l -> first);
            l++;
        }
        else
        {
            if (r -> second == 4)
            {
                need_room = 1;
                last_changes = res.size() - 1;
            }
            res.push_back(r -> first);
            r++;
        }
    }
    For(i, 0, last_changes)
    cout << res[i] << ' ';
    while (l != leftt.end())
    {
        cout << l -> first << ' ';
        l++;
    }
    while (r != rightt.end())
    {
        cout << r -> first << ' ';
        r++;
    }
    For(i, last_changes + 1, res.size() - 1)
        cout << res[i] << ' ';
    cout << right_end;

}

void input()
{
    cin >> n;
    For(i, 1, n)
    {
        ll x, a;
        cin >> x >> a;
        if (x == 5 || x == 6) 
            t[1] = x,
            res.push_back(a);
        if (x == 7 || x == 8) 
            t[n] = x,
            right_end = a;
        if (x == 1) cnt1++;
        if (x == 4) cnt4++;
        if (x == 1 || x == 2) leftt.push_back(ii(a, x));
        if (x == 3 || x == 4) rightt.push_back(ii(a, x));
    }
}

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    input();
    process();
}