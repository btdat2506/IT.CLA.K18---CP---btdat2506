#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n, s = 0;
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        s += c;
    }
    cout << s % 2 << endl;
}