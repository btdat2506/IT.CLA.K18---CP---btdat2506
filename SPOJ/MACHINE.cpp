#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define f0(i, b) for(ll i = 0; i < b; i++)

const ll N = 100010;
ll n, time_a, time_b, time_c, a[N], b[N], c[N];
vector <ll> t1, t2, k1, k2;

bool cmp1(const ll &L, const ll &R)
{
    return t1[L] < t1[R];
}

bool cmp2(const ll &L, const ll &R)
{
    return t2[L] > t2[R];
}

void process()
{
    f0(i, n)
    {
        t1.push_back(a[i] + b[i]);
        t2.push_back(b[i] + c[i]);
    }
    f0(i, n)
    if (t1[i] < t2[i]) 
        k1.push_back(i);
    else
        k2.push_back(i);
    sort(k1.begin(), k1.end(), cmp1);
    sort(k2.begin(), k2.end(), cmp2);
    for(ll t: k2) k1.push_back(t);
    f0(i, n)
    {
        time_a += a[k1[i]];
        time_b = max(time_a, time_b) + b[k1[i]];
        time_c = max(time_b, time_c) + c[k1[i]];
    }
    cout << time_c << "\n";
    for(ll t: k1)
    cout << t+1 << ' ';
}

void input()
{
    cin >> n;
    f0(i, n)
    cin >> a[i];
    f0(i, n)
    cin >> b[i];
    f0(i, n)
    cin >> c[i];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    input();
    process();
}