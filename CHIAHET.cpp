#include <bits/stdc++.h>

using namespace std;

string sub(string a, string b)
{
    string c = "";
    int borrow = 0, s = 0;
    while (a.length() < b.length()) a = '0' + a;
    while (b.length() < a.length()) b = '0' + b;
    for (int i = a.length()-1; i >= 0; i--)
    {
        s = ((int) (a[i] - 48)) - ((int) (b[i] - 48)) - borrow;
        if (s < 0)
        {
            s += 10;
            borrow = 1;
        }
        else borrow = 0;
        c = ((char) (s + 48)) + c;
    }
    while (c.length() > 1 && c[0] == '0') c.erase(1 , 1);
    return c;
}

int Mod(string a, int b)
{
    int hold = 0;
    for (int i = 0; i < a.length(); i++)
        hold = (((int) a[i] - 48) + hold * 10) % b;
    return hold;
}

int main()
{
    string st;
    cin >> st;
    if (Mod(st, 11) != 0)
    {
        cout << "False" << endl;
        return 0;
    }
    while (st.length() > 2)
    {
        string st1 = "";
        st1 += st[st.length()-1];
        st.erase(st.length()-1, 1);
        st = sub(st, st1);
        cout << st << endl;
    }
    int so = ((int) st[0] - 48) * 10 + ((int) st[1] - 48) ;
    if (so % 11 == 0) cout << "True" << endl; else cout << "False" << endl;
    return 0;
}
