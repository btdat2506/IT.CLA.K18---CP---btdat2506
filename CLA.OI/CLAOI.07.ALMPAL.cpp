#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, dem = 0;
    string st;
    unordered_map <char, int> sl; //so lan xuat hien tung chu
    set <char> ch; //cac chu co xuat hien trong st
    cin >> n;
    cin >> st;
    for(int i = 0; i < n; i++)
    {
        sl[st[i]]++;
        ch.insert(st[i]);
    }
    for (auto x: ch)
    if (sl[x] % 2 != 0) {dem++; if (dem > 1) {cout << "NO"; return 0;}}
    cout << "YES"; return 0;
}
