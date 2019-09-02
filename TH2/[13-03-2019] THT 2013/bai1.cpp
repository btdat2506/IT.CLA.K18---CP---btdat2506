#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

string ck, inp;

void init(int dem)
{
    if (dem == 1) ck = "ONE";
    if (dem == 2) ck = "TWO";
    if (dem == 3) ck = "THREE";
    if (dem == 4) ck = "FOUR";
    if (dem == 5) ck = "FIVE";
    if (dem == 6) ck = "SIX";
    if (dem == 7) ck = "SEVEN";
    if (dem == 8) ck = "EIGHT";
    if (dem == 9) ck = "NINE";
}

int main()
{
    cin >> inp;
    For(dem, 1, 9)
    {
        string xuli = inp;
        init(dem);
        ll i = 0;
        while (xuli.length() != 0)
        {
            cout << ck << endl;
            while (xuli[0] != ck[i] && xuli.length() != 0) xuli.erase(0, 1);
            i++;
            if (i == ck.length()) {cout << ck << endl; return 0;}
        }
    }
    cout << "KHONG" << endl;
}