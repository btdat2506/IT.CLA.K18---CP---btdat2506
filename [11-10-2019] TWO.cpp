#include <bits/stdc++.h>

using namespace std;

#define ll int
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, R1, R2, ans, timeA, timeB, a[10010], b[10010], d1[10010], d2[10010];

bool cmp (const ll &l, const ll &r)
{
	return a[l] < a[r];
}

bool cmp1 (const ll &l, const ll &r)
{
	return b[l] > b[r];
}

//chú ý điều kiện sort

void process()
{
	For(i, 1, n)
		if (a[i] < b[i]) d1[++R1] = i; else d2[++R2] = i;
	sort(d1+1, d1+1+R1, cmp);
	sort(d2+1, d2+1+R2, cmp1);
	copy(d2+1, d2+1+R2, d1+1+R1);
	For(i, 1, n)
	{
		timeA += a[d1[i]];
		if (timeA >= timeB) timeB = timeA + b[d1[i]];
		else 
			timeB += b[d1[i]];
	}
	cout << timeB << "\n";
	For(i, 1, n) cout << d1[i] << ' ';
}

void input()
{
	cin >> n;
	For(i, 1, n) cin >> a[i];
	For(i, 1, n) cin >> b[i];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	process();
}