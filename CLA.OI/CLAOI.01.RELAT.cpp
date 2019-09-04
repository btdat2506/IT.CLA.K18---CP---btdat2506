#include <bits/stdc++.h>

using namespace std;

vector <int64_t> a, b;
unordered_map <int64_t, int64_t> sl;
set <int64_t> spt;
int64_t n;
#define For(i, a, b) for(int64_t i = a; i <= b; i++)

void input()
{
    cin >> n;
    a.resize(n+10);
    b = a;
    For(i, 1, n)
    {
        cin >> a[i];
        sl[a[i]]++; //so luong so a[i]
        spt.insert(a[i]); // so cac so a
        b[i] = a[i] + b[i-1];
    }
}

int main()
{
    input();
    cout << b[n]/2;
    return 0;
}
