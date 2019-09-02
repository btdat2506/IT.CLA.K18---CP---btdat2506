#include <bits/stdc++.h>

using namespace std;
int64_t a, b[100000], g, kq = 0;

string chuyenhecoso(int n)
{
    string st;
    while (n > 0)
    {
        st = to_string(n % g) + st;
        n /= g;
    }
    return st;
}

int hecoso10(string st)
{
    for (int i = 0; i < st.length()-1; i++) (kq += (int) (st[i]-48)) *= g;
    return kq + ((int) (st[st.length()-1] - 48));
}

int main()
{
    cin >> a >> g;
    cout << chuyenhecoso(a) << endl;
    cout << hecoso10(chuyenhecoso(a)) << endl;
    return 0;
}
/*int64_t data = a, dem = 0;
    while (a > 0) {dem++; b[dem] = a % 10; a /= 10;}
    a = data;
    for (int i = 1; i < dem; i++)
    (kq += b[i]) *= g;
    cout << kq + b[dem] << endl;*/
