#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<ll, string> istr;
#define fi first
#define se second
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define f0(i, b) for(ll i = 0; i < b; i++)

bool isTaxi(string tmp)
{
	return tmp[0] == tmp[1] && tmp[1] == tmp[3] && tmp[3] == tmp[4] && tmp[4] == tmp[6] && tmp[6] == tmp[7];
}

bool isPizza(string tmp)
{
	return tmp[0] > tmp[1] && tmp[1] > tmp[3] && tmp[3] > tmp[4] && tmp[4] > tmp[6] && tmp[6] > tmp[7];
}



int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("TELEPHONE.INP", "r", stdin);
	freopen("TELEPHONE.OUT", "w", stdout);
	ll t;
	cin >> t;
	vector <istr> tx(t), pz(t), fr(t);
	f0(i, t)
	{
		ll n;
		string id, tmp;
		set <string> num;
		cin >> n >> id;
		f0(j, n)
		{
			cin >> tmp;
			num.insert(tmp);
		}
		pz[i].se = tx[i].se = fr[i].se = id;
		for(auto tmp2: num)
		if (isPizza(tmp2)) pz[i].fi++; else
		if (isTaxi(tmp2)) tx[i].fi++; else
		fr[i].fi++;
	}
	sort(pz.begin(), pz.end(), greater<istr>());
	sort(fr.begin(), fr.end(), greater<istr>());
	sort(tx.begin(), tx.end(), greater<istr>());

	auto find_max = [](vector <istr> &t, string name)
	{
		ll max_val = t[0].first;
		cout << name << ": " << t[1].se;
		for(ll i = 1; i < t.size() && t[i].first == max_val; i++)
		cout << ", " << t[i].se; cout << ". \n";
	};

	find_max(tx, "Taxi");
	find_max(pz, "Pizza");
	find_max(fr, "Friends");
}