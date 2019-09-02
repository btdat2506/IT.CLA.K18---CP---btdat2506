#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i < b; i++)

ll n, mu = 0, dao = 0;

void process()
{
	do mu *= 2; while (mu < n);
	while (n != 1 && n != 2)
	{
		if (n > mu/2) n = (mu / 2) - (mu - n), dem++;
		if (xl >= 2) xl /= 2;
	}
	n %= 2, dem %= 2;
	cout << (n + dem) % 2 << endl;
}

int main()
{
	//freopen("DIGIT.INP", "r", stdin);
	//freopen("DIGIT.OUT", "w", stdin);
	cin >> n;
	process();
}