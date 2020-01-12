#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, s, arr[100010];

void process()
{
	arr[n+1] = 1e12;
	ll res = 0, id_max = 1;
	bool removed = 0;
	For(i, 1, n)
	{
		//cộng arr[i] vào, nếu xóa mà vẫn +arr[i+1] được thì xóa, xcòn không thì trả lạilại
		id_max = (!removed && arr[i] > arr[id_max]) ? i : id_max;
		res += arr[i];
		if (res >= s)
		{
			if (!removed && res - arr[id_max] + arr[i+1] <= s)
				res = res - arr[id_max],
				removed = 1;
			else
				if (removed) break;
		}	
	}
	cout << ((removed) ? id_max : 0) << "\n";
}

void input()
{
	cin >> n >> s;
	For(i, 1, n)
	cin >> arr[i];
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("test.in", "r", stdin);
	freopen("test.ok", "w", stdout);
	ll t;
	cin >> t;
	while(t--)
	{
		input();
		process();
	}
}