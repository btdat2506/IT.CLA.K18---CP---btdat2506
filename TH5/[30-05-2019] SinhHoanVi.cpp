#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i++)

ll a[10000], siz;

void SinhHoanVi(ll n)
{
	For(i, 1, n)
	if (n != i)
	{
		swap(a[i], a[n]);
		For(i, 1, siz)
		cout << a[i];
		cout << endl;
		if (n < siz) SinhHoanVi(n+1);
		swap(a[i], a[n]);
	} else 
		if (n < siz) SinhHoanVi(n+1);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ll n, n1, i = 0;
	cin >> n;
	n1 = n;
	stack <ll> st;
	a[0] = 0;
	while (n1 != 0)
	{
		st.push(n1%10);
		n1 /= 10;
	}
	siz = st.size();
	while (st.size() != 0)
	{
		i++;
		a[i] = st.top();
		st.pop();
	}
	cout << n << endl;
	SinhHoanVi(1);
}