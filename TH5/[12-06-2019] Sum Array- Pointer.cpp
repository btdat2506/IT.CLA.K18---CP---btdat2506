#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

ll a[10], n = 9, *pa;

void process()
{
	For(i, 1, n)
	*(pa + i) += *(pa + i - 1);
	cout << *(pa + 9) << endl;
	cout << &a[3] << endl;
}

void input()
{
	pa = a;
	For(i, 0, n)
	cin >> *(pa + i);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();	
}