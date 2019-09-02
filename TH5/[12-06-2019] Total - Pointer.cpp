#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

ll a[10], n = 9, *pa;

void process()
{
	For(i, 0, n)
	{
		cout << a[i] << endl;
		cout << pa[i] << endl;
		cout << *(a + i) << endl;
		cout << *(pa + i) << endl;
	}
}

void input()
{
	pa = a;
	For(i, 0, n)
	{
		cin >> a[i];
		cin >> pa[i];
		cin >> *(a + i);
		cin >> *(pa + i);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();	
}