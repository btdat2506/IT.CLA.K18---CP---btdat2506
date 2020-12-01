#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define f0(i, n) for(ll i = 0; i <= n; i++)

const ll N = 10010, STATE = (1 << 4) + 2;
ll n, ans = -1e12, db[5][10010], f[N][STATE];

/* 2 con bug:
- RTE - tràn bộ nhớ
- set giá trị ans sai 
- memset ẩu trong bug2 dẫn tới tràn biến
*/

bool getBit(ll k, ll pos)
{
	return (k >> pos) & 1;
}

bool isValid(ll j, ll k)
{
	//Kiểm tra nếu có 2 bit 1 liền kề
	ll tmp = j << 1;
	while (tmp >>= 1)
	{
		if (getBit(tmp, 0) && getBit(tmp, 1))
		return false;
	}
	tmp = k << 1;
	while (tmp >>= 1)
	{
		if (getBit(tmp, 0) && getBit(tmp, 1))
		return false;
	}
	//Kiểm tra 2 bit liền kề giữa 2 hàng
	tmp = j & k;
	if (tmp == 0) 
		return true;
	return false;
}

ll getValue(ll i, ll k)
{
	ll sum = 0, pos = 5;
	k <<= 1;
	while (k >>= 1)
	{
		pos--;
		if (getBit(k, 0))
		sum += db[pos][i];
	}
	return sum;
}

void process()
{
	//memset
	ans = -1e12;
	For(i, 0, N-1)
	f0(j, STATE-1)
	f[i][j] = -1e12;
	//memset
	For(k, 1, (1 << 4) - 1)
	if (isValid(k, 1 << 6))
	{
		//cout << k << " ";
		f[1][k] = getValue(1, k);
		//cout << f[1][k] << '\n';
	}
	For(i, 2, n)
	f0(j, (1 << 4) - 1)
	f0(k, (1 << 4) - 1)
	if (isValid(j, k))
	{
		f[i][k] = max(f[i][k], f[i-1][j] + getValue(i, k));
	}
	f0(k, (1 << 4) - 1)
	ans = max(ans, f[n][k]);
	cout << ans << "\n";
}

void input()
{
	cin >> n;
	For(i, 1, 4)
	For(j, 1, n)
	cin >> db[i][j];
}

int main()
{
	input();
	process();
}