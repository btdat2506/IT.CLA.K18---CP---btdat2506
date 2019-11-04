#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, k, vt1, vt2, a[100010], pros[100010];
double ans = 0, ans1 = 0;

void process()
{
    For(i, 1, n) pros[i] = pros[i-1] + a[i];
	For(i, k, n)
	{
		pros[i] = a[i] + pros[i-1];
		ll l = 1, r = i - k + 1, mid = (l + r) / 2;
		while (l != mid && r != mid)
		{
			if ((pros[i] - pros[mid - 1]) / (i - mid + 1) < ans)
				l = mid;
			else
				ans = max(ans, (double) ((double) (pros[i] - pros[mid - 1]) / (double) (i - mid + 1))),
				r = mid;
            mid = (l + r) / 2;
		}
		ans = max(ans, (double) ((double) (pros[i] - pros[mid - 1]) / (double) (i - mid + 1)));
	}
	For(i, 1, n-k)
	For(j, i+k, n) 
	if ((double)((double)pros[j] - (double)pros[i-1]) / (double)(j - i + 1) > ans1)
	{
		ans1 = (double)((double)pros[j] - (double)pros[i-1]) / (double)(j - i + 1);
		vt1 = i, vt2 = j;
	} 
	cout << ans << ' ' << ans1 << "\n";
	cout << vt1 << ' ' << vt2 << "\n";
}

void input()
{
	cin >> n >> k;
	For(i, 1, n) cin >> a[i];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cout << setprecision(5) << fixed;
	input();
	process();
}
