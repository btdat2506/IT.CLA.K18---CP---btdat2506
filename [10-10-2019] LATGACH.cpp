#include <bits/stdc++.h>

using namespace std;

#define f0(i, n) for(int i = 0; i < n; i++)
#define f1(i, n) for(int i = 1; i <= n; i++)
#define For(i, a, b) for(int i = a; i <= b; i++)

typedef vector <int64_t> vi;
const int64_t BASE = 10000;

vector <vi> f;

void fix(vi &a)
{
    a.push_back(0);
    f0(i, a.size()-1)
    {
        a[i+1] += a[i]/BASE;
        a[i] %= BASE;
        if (a[i] < 0)
            a[i] += BASE,
            a[i+1]--;
    }
    while (a.size() >= 2 && a.back() == 0) a.pop_back();
}

void operator += (vi &a, const vi &b)
{
    a.resize(max(a.size(), b.size()));
    f0(i, b.size()) a[i] += b[i];
    fix(a);
}

vi operator + (vi a, const vi &b)
{
    a += b;
    return a;
}

vi to_vi(int x)
{
    return vi(1, x); // x < BASE
}

ostream& operator << (ostream& cout, const vi &a){
    printf("%d", a.back());
    for (int i=(int)a.size()-2; i>=0; i--)
    printf("%04d", a[i]);
    return cout;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    f.resize(110);
    f[1] = to_vi(1);
    f[2] = to_vi(2);
    For(i, 3, 100)
    f[i] = f[i-1] + f[i-2];
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << f[n] << "\n";
    }
}