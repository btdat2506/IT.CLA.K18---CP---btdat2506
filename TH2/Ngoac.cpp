#include <bits/stdc++.h>

using namespace std;
#define For(i, a, b) for(int i = a; i <= b; i++)
stack <char> database;
bool check(char ch)
{
    char ch1 = database.top();
    if (ch == ']' && ch1 == '[') return 1;
    if (ch == ')' && ch1 == '(') return 1;
    if (ch == '}' && ch1 == '{') return 1;
    return 0;
}

int main()
{
    int n;
    cin >> n;   
    For(i, 1, n)
    {
        char ch;
        cin >> ch;
        if (database.size() == 0) database.push(ch); else
        if (check(ch) == 0) database.push(ch); else 
        if (check(ch) == 1) database.pop();
    }
    if (database.size() == 0) cout << "True" << endl; else cout << "False" << endl;
    system("pause");
    return 0;
}