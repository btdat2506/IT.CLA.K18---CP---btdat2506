#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n;
pair <ll, ll> pr[100];

voidBFS)
{

}
bool cmp (const pair <ll, ll> &L, const pair <ll, ll> &R)
{
    if (L.first == R.first)
        return L.second < R.second;
    return L.first < R.first;
}

void process()
{
    sort(pr+1, pr+1+n, cmp);
    For(i, 1, n)
    cout << pr[i].first << ' ' << pr[i].second << "\n";
}

void input()
{
    cin >> n;
    For(i, 1, n)
    {
        cin >> pr[i].first >> pr[i].second;
    }
}

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    input();
    process();
}