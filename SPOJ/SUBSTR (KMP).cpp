#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i < b; i++)

const ll N = 1000010;
ll n, m, b[N];
string txt, pt;

void kmpPreprocess()
{
    ll i = 0, j = -1;
    b[0] = -1;
    while (i < m)
    {
        while (j >= 0 && pt[i] != pt[j]) j = b[j];
        i++, j++;
        b[i] = j;
    }
}

void kmpSearch()
{
    ll i = 0, j = 0;
    while (i < n)
    {
        while (j >= 0 && txt[i] != pt[j]) j = b[j];
        i++, j++;
        if (j == m)
        {
            cout << i - j + 1 << " ";
            j = b[j];
        }
    }
}

void process()
{
    n = txt.size(), m = pt.size();
    kmpPreprocess();
    kmpSearch();
}

void input()
{
    cin >> txt >> pt;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    input();
    process();
}