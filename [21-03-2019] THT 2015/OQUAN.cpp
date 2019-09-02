#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll stt, vt, stat, a[4][10];

void PrintResult()
{
	For(i, 1, 2)
	{
		For(j, 1, 5)
		cout << a[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
}

void reset_variable(ll &x, ll &y, ll &z)
{
	// đặt lại khi bị lố ra khỏi ô quan
	if (y == 0 || y == 6) x = (x == 2) ? 1 : 2, z = (z == 1) ? -1 : 1;
	if (y == 6) y = 5; if (y == 0) y = 1;
}

void process()
{
	ll hang = stt, cot = vt, chieu, sl = a[hang][cot];
	if (stat) //STAT = 1 là đi ngược chiều kim đồng hồ
	if (hang == 2) chieu = +1; else chieu = -1; 
	//ở hàng 2 thì sẽ đi sang phải, còn ở hàng 1 thì đi sang trái
	else //stat = 0, chiều kim đồng hồ
	if (hang == 2) chieu = -1; else chieu = +1;
	while (cot >= 1 && cot <= 5 && a[hang][cot] > 0)
	//mặc định ô quan sẽ là cột 0 và 6 trong cả 2 mảng
	{
		ll sl = a[hang][cot];
		a[hang][cot] = 0;
		For(i, 1, sl)
		{
			cot += chieu;
			reset_variable(hang, cot, chieu);
			a[hang][cot]++;
			PrintResult();
		}
		cot += chieu;
	}
}

void input()
{
	memset(a, 0, sizeof(a));
	cin >> stt >> vt >> stat;
	For(i, 1, 2)
	For(j, 1, 5)
	cin >> a[i][j];
}

int main()
{
	freopen("OQUAN.IN", "r", stdin);
	freopen("OQUAN.OU", "w", stdout);
	input();
	process();
	PrintResult();
}