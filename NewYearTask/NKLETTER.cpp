#include <bits/stdc++.h>
 
using namespace std;
string st1, st2;
bool kt = 0;
int j;
 
int main()
{
    cin >> st1;
    cin >> st2;
    for(j = 0; j < st1.length(); j++)
    if (st2.find(st1.substr(j, st1.length()-1)) == 0) break;
    cout << j + st2.length() << endl;
} 