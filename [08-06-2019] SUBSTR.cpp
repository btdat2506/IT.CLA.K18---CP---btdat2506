#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

struct cmp
{
	bool operator () (const ll &L, const ll &R)
	{
		return L > R;
	}
};

string st1 = "", st2 = "";
ll a = 0, b = 0;
priority_queue <ll, vector<ll>, cmp> pq;

ll convert(string st_temp)
{
	ll temp = 0;
	For(i, 1, st2.length()-1)
		temp += (((st_temp[i]) - 'a' + 1) * pow(27, st2.length() - 1 - i)); 
	return temp;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> st1 >> st2;
	st1 = ' ' + st1;
	st2 = ' ' + st2;
	a = convert(st1),
	b = convert(st2);
	if (a == b) cout << 1;
	if (st1 == st2) return 0;
	For(i, 2, st1.length()-st2.length()+1)
	{
		a = (a - ((st1[i-1] - 'a' + 1) * pow(27, st2.length()-2))) * 27 + (st1[i+st2.length()-2] - 'a' + 1);
		if (a == b) cout << ' ' << i;
	}
	return 0;
}

//KMP, z-algo