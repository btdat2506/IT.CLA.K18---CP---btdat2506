#include <bits/stdc++.h>

using namespace std;

struct NT
{
    int C, H, O = {0};
};

NT PT[3];

int SL(string st, int i) 
{
    if (st[i+1] >= '2' && st[i+1] <= '9') 
    return (int) st[i+1] - 48; else return 1;
}

void XuLi(char ch, int sl, int i)
{
    if (ch == 'C') PT[i].C += sl;
    if (ch == 'H') PT[i].H += sl;
    if (ch == 'O') PT[i].O += sl;
}

int main()
{
    string st, st1, st2, st3;
    cin >> st;
    int dem = 0;
    while (st[dem] != '+') dem++;
	for (int i = 0; i < dem; i++) st1 += st[i];
    int temp = dem;
    while (st[dem] != '=') dem++;
    for (int i = temp+1; i < dem; i++) st2 += st[i];
    for (int i = dem+1; i < st.length(); i++) st3 += st[i];
    for (int i = 0; i < st1.length(); i++) XuLi(st1[i], SL(st1, i), 0);
    for (int i = 0; i < st2.length(); i++) XuLi(st2[i], SL(st2, i), 1);
    for (int i = 0; i < st3.length(); i++) XuLi(st3[i], SL(st3, i), 2);
    for (int i = 1; i < 11; i++)
    for (int j = 1; j < 11; j++)
    for (int k = 1; k < 11; k++)
    if ((PT[0].C*i + PT[1].C*j == PT[2].C*k) && (PT[0].H*i + PT[1].H*j == PT[2].H*k) && (PT[0].O*i + PT[1].O*j == PT[2].O*k))
    {
        cout << i << " " << j << " " << k << endl;
        system("pause");
        return 0;
    }
    
}