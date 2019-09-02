#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

void hoanvi (ll *x, ll *y)
{
	swap(*x, *y);
}

void process()
{
	ll n = 10, *pa = &n;
	//cout << pa << endl; //gt
	//cout << *pa << endl; //gt vung nho tro den
	//cout << &pa << endl; //dia chi
	//size
	/*cout << sizeof(ll *) << endl;
	cout << sizeof(char *) << endl;
	cout << sizeof(string *) << endl;*/
	//ll x = 5, y = 6;
	//hoanvi(&x, &y);
	//cout << x << endl << y << endl;
	
}

void input()
{
	
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	input();
	process();	
}