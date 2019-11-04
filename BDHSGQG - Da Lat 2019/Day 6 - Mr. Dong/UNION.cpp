#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, res, pos, v[300010];
queue <ll> qu;

void process()
{
	sort(v+1, v+1+n);
	qu.push(0);
	pos = n; //bắt đầu từ n
	while (pos > 0 || !qu.empty()) //lưu ý những vị trí trong lúc duyệt (pos)
	{
		if (qu.front() >= v[pos])
		{
			ll u = qu.front();
			while (v[pos] == u) pos--;
			while (qu.front() == u) qu.pop();
			if (!qu.empty())
			{
				res++;
				qu.push(u/2);
			}
		}
		else
		{
			qu.push(v[pos]/2);
			pos--;
			while (v[pos] == v[pos + 1]) pos--;
			res++;
		}
		while (qu.front() == 0 && !qu.empty()) 
			qu.pop();
	}
	cout << res;
}

void input()
{
	cin >> n;
	For(i, 1, n) cin >> v[i];
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
	freopen("UNION.INP", "r", stdin);
	freopen("UNION.OUT", "w", stdout);
	input();
	process();
}
