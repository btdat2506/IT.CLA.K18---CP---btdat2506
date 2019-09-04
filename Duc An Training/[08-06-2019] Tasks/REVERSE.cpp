#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

string st;
ll m, req[200], cnt[250];
queue <ll> q;

void reverse(ll pos)
{
	ll left = pos - 1,
	   right = st.length() - pos;
	while (left < right)
	{
		swap(st[left], st[right]);
		left++;
		right--;
	}

}

void process()
{
	sort(req+1, req+m+1);
	For(i, 1, m) cnt[req[i]] = 0;
	For(i, 1, m) cnt[req[i]]++;
	For(i, 1, m) 
	if (cnt[req[i]] % 2 != 0 && req[i] != req[i-1])
		q.push(req[i]);
	while (q.size() != 0)
	{
		reverse(q.front());
		q.pop();
	}
	cout << st << endl;
}

void input()
{
	req[0] = INT64_MIN;
	cin >> st;
	cin >> m;
	For(i, 1, m) cin >> req[i];
}

int main()
{
	freopen("REVERSE.INP", "r", stdin);
	freopen("REVERSE.OUT", "w", stdout);
	input();
	process();	
}