#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

void process(ll str, ll smart, ll exp)
{
	str -= smart;
	smart = 0;
	ll ans = exp - (str - 1);
	ll str_origin = str, smart_origin = smart, exp_origin = exp;
	while (str != smart + 1)
	{
		exp--;
		ll cnt = exp_origin - exp;
		if (cnt + smart < str)
		{
			
		}
		else
		{

		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ll t;
	while(t--)
	{
		ll str, smart, exp;
		cin >> str >> smart >> exp;
		if (exp == 0)
		{
			if (str > smart) cout << 1 << endl; else cout << 0 << endl;
		}
		else
		{
			if (str < smart)
			{
				if (str + exp <= smart) cout << 0 << endl;
				else
				{
					exp -= (smart - str - 1);
					str += (smart - str - 1);
					process(str, smart, exp);
				}
			}
			else
			if (str > smart)
			process(str, smart, exp);
		}
	}
}

//ans = (e+s) - max(e, (e+s+i)/2)