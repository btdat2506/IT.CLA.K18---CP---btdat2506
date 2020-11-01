#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

const ll N = 100010;
ll n, time_a, time_b, a[N], b[N];
vector <ll> t1, t2;

bool cmp1(const ll &L, const ll &R)
{
    return a[L] < a[R];
}

bool cmp2(const ll &L, const ll &R)
{
    return b[L] > b[R];
}

void process()
{
    For(i, 1, n)
    if (a[i] < b[i]) 
        t1.push_back(i);
    else
    {
        t2.push_back(i);
    }
    sort(t1.begin(), t1.end(), cmp1);
    sort(t2.begin(), t2.end(), cmp2);
	for(ll t: t2) t1.push_back(t);
	For(i, 0, n-1)
	{
		time_a += a[t1[i]];
		time_b = max(time_a, time_b) + b[t1[i]];
	}
    cout << time_b << "\n";
	For(i, 0, n-1)
	cout << t1[i] << ' ';
}

void input()
{
    cin >> n;
    For(i, 1, n)
    cin >> a[i];
    For(i, 1, n)
    cin >> b[i];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    input();
    process();
}