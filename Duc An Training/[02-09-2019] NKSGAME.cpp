#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, l1 = -1, l2 = -1, ans = 0, arr1[100010], arr2[100010], pros[100010];

ll bSearch_positive(ll x)
{
	int tmp = 0,res=0;
	ll l = l2, r = n;
	while (l-r != 1)
	{
		ll mid = (l + r) / 2;
		if (abs(arr2[mid]) >= x) {
			r = mid-1; 
		} else l = mid+1;
		if (tmp < arr2[mid]+x){
				tmp = arr2[mid] + x;
				res = mid;
		}
	}
	return res;
}

ll bSearch_negative(ll x)
{
	int tmp = INT_MAX,res=0;
	ll l = 1, r = l2;
	while (l-r!=1)
	{
		ll mid = (l + r) / 2;
		if (abs(arr2[mid]) >= x) l = mid+1; else r = mid-1;
		if (tmp > arr2[mid]+x){
				tmp = arr2[mid] + x;
				res = mid;
		}
	}
	return l;
}

void process()
{
	sort(arr2+1, arr2+n+1);
	For(i, 1, n)
	if (l2 == -1 && arr2[i] >= 0) l2 = i;
	if (l2 == -1) l2 = n;
	For(i, 1, n)
	if (arr1[i] < 0)
		pros[i] = lower_bound(arr2+1+l2, arr2+n+1, arr1[i]) - (arr2+1);
		//pros[i] = bSearch_positive(arr1[i]);
	else
		pros[i] = lower_bound(arr2+1, arr2+1+l2, arr1[i]) - (arr2+1);
		//pros[i] = bSearch_negative(arr1[i]);
	ans = abs(arr1[1] + arr2[pros[1]]);
	For(i, 2, n)
	ans = min(ans, abs(arr1[i] + arr2[pros[i]]));
	cout << ans << endl;
}

void input()
{
	cin >> n;
	For(i, 1, n)
	cin >> arr1[i];
	For(i, 1, n)
	cin >> arr2[i];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}