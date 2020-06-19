#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n; //length of st1
ll m; //length of st2
string st1, st2;

vector <ll> kmp_pre_process(string st) //create back table using KMP
{
    vector <ll> b (st.length()+10, 0); //back table
    ll i = 0, j = -1;
    b[0] = -1;
    while (i < st.length())
    {
        while (j >= 0 && st[i] != st[j]) j = b[j];
        i++, j++;
        b[i] = j;
    }
    return b;
}

void kmpSearch(vector <ll> b)
{
    ll i = 0, j = 0;
    while (i <= n)
    {
        while (j >= 0 && st1[i] != st2[j]) j = b[j];
        i++, j++;
        if (j == m)
        {
            cout << i - j + 1 << ' ';
            j = b[j];
        }
    }
}

void process()
{
    kmpSearch(kmp_pre_process(st2));
}

void input()
{
    cin >> st1 >> st2;
    n = st1.length();
    m = st2.length();
    /* st1 = ' ' + st1;
    st2 = ' ' + st2; */
}

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    input();
    process();
}