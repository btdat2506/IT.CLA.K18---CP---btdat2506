#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;
typedef pair<ll, string> istr;
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define f0(i, n) for(ll i = 0; i < n; i++)
//ifstream (NAME);
//ofstream (NAME);

ll n;
string st, ans;
vector< pair<char, ll> > t;

string case1(string &t1, ll cnt)
{
	string tmp = "";
	f0(i, cnt)
	tmp += t1;
	return tmp;
}

string case2_1(string &t1)
{
	t1.erase(0, 1);
	string t2 = t1;
	reverse(t2.begin(), t2.end());
	return t1 + t2;
}

string case2_2(string &t1)
{
	t1.erase(t1[t1.size() - 1], 1);
	string t2 = t1;
	reverse(t2.begin(), t2.end());
	t2.erase(0, 1);
	return t1 + t2;
}

string get_res(string &t1, ll le)
{
	if (t[le].first == '(') return case1(t1, st[t[le].first - 1] - '0');
	if (t[le].first == '[')
	{
		if (*t1.begin() == '*') return case2_1(t1);
		if (*t1.end() == '*') return case2_2(t1);
	}
	return "";
}

void process()
{
	n = st.length();
	f0(i, n)
	if ((st[i] == '(') || (st[i] == ')') || (st[i] == '[') || (st[i] == ']'))
	t.push_back({st[i], i});
	ll le = 0, ri = 0, cnt = 0;
	string t1 = "";
	while (le < n)
	{
		while ((t[le].first == '(' || t[le].first == '[') && le < n) 
			le++, cnt++;
		ri = le + 1;
		string t2 = st.substr(t[le].second + 1, t[ri].second - t[le].second - 1);
		t1 = get_res(t2, le);
		le--, ri++, cnt--;
		t1 = st.substr(t[le].second + 1, t[le + 1].second - t[le].second - 1) + t1 + st.substr(t[ri].second + 1, t[ri].second - t[ri - 1].second - 1);
		while (cnt != 0)
		{
			t1 = get_res(t1, le);
			le--, ri++, cnt--;
			t1 = st.substr(t[le].second + 1, t[le + 1].second - t[le].second - 1) + t1 + st.substr(t[ri].second + 1, t[ri].second - t[ri - 1].second - 1);
		}
		ans += t1,
		le = ri + 1,
		t1 = "";
	}
	cout << ans << "\n"; 
}

void input()
{
	cin >> st;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	input();
	process();
}