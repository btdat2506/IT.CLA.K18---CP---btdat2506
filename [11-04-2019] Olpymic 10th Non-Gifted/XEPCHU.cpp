#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

string st[1000];
ll siz = 0, slkt = 0;

void process()
{
	sort(st, st+siz);
	For(i, 0, siz) slkt += st[i].length();
	cout << siz << " " << slkt + siz - 1 << endl;
	For(i, 0, siz) cout << st[i] << " ";
}

int main()
{
	freopen("XEPCHU.INP", "r", stdin);
	freopen("XEPCHU.OUT", "w", stdout);
	string x = "";
	while (cin >> x) st[siz] = x, siz++;
	process();
}