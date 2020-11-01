#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a-1; i < b; i++)

ll rand(ll l, ll r)
{
    return l + rand() % (r - l + 1);
}

int main()
{
    srand(time(NULL));
    freopen("test.ok", "w", stdout);
    ll n = rand(5, 50), j = 0;
    string st = "", st2 = "", st3 = "";
    For(i, 1, n)
    st += (char) rand(32, 255);
    ll k = rand(2, n);
    For(i, 1, k)
    st3 += 'a' + rand(0, 25);
    For(i, 1, n)
    {
        if ((st[i] >= 'a' && st[i] <= 'z') || (st[i] >= 'A' && st[i] <= 'Z')){
            char c = (st[i] + st3[j] - 2*'a') % 26 + 'a';
            if (st[i] >= 'A' && st[i] <= 'Z')  c = (st[i] + st3[j] - 2*'A') % 26 + 'A';
            st2.push_back(c);
        }
        else
        st2 += st[i];
        j++;
        if (j == k) j = 0;
    }
    cout << n << "\n" << st << "\n" << st2 << "\n" << st3 << "\n";
}