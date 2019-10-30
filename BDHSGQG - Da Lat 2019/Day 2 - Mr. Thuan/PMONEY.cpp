#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

typedef pair<ll, ll> ii;

string st, st1;
ll n, a, b, c, plus_s, minus_s, zero_s, ab, zero_s1, ans_min, ans_max, prefix[1000010];

void replace(ll i)
{
	if (plus_s != 0) 
		st[i] = '+',
		plus_s--;
	else
	if (zero_s != 0)
		st[i] = '0',
		zero_s--;
	else
	if (minus_s != 0)
		st[i] = '-',
		minus_s--;
}

ll calc()
{
	ll val = 0, x = 0;
	For(i, 1, n)
	{
		if (st[i] == '+') x++;
		if (st[i] == '-') x--;
		val += x;
		if (x < 0) return -1;
	}
	if (x < 0) return -1;
	return val;
}

ll calc_min()
{
	st = st1;
	stack <ii> stack_k;
	For(i, 1, n)
    {
        if (st1[i] == '-' || st1[i] == '_')
            prefix[i] = prefix[i - 1] - 1;
        else 
        if (st[i] == '+')
            prefix[i] = prefix[i - 1] + 1;
        else
            prefix[i] = prefix[i - 1];
    }
    ll cnt = 0;
    For(i, 1, n)
    {
        if (st1[i] == '_')
        {
            st[i] = '-';
            stack_k.push(ii(i, 2));
        }
        while (prefix[i] + cnt < 0)
        {
            ll val = stack_k.top().second, pos = stack_k.top().first;
            stack_k.pop();
            if (prefix[i] + cnt + val > 0)
            {
                stack_k.push(ii(pos, 1));
                cnt++;
                st[pos] = '0';
            }
            else
            {
                st[pos] = '+';
                cnt += val;
            }
        }
    }
    ll Min = 0, x = 0;
    For(i, 1, n)
    {
        if (st[i] == '+') x++; else 
        if (st[i] == '-') x--;
        Min += x;
    }
    return Min;
}

int main()
{
   // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	cin >> st;
	n = st.length();
	st = ' ' + st;
	st1 = st;
	//count mark on each char
	For(i, 1, n)
	if (st[i] == '+') a++; else
	if (st[i] == '-') b++; else
	if (st[i] == '0') c++;
	//replace mark and calculate max
	/*plus_s = minus_s = 0;
	if (a > b) minus_s = a - b; else plus_s = b - a;
	zero_s = n - a - b - c - minus_s - plus_s;
	Fod(i, n, 1)
	if (st[i] == '_') replace(i);
	ans_min = calc();*/
	//re_replace, memset mark and calculate max
	if ((n - c) % 2 != 0) zero_s = 1; else zero_s = 0;
	ab = (n - c - zero_s) / 2;
	plus_s = ab - a;
	minus_s = ab - b;
	st = st1;

	For(i, 1, n)
	if (st[i] == '_') replace(i);
	ans_max = calc();
	//Print Result
	if (ans_max == -1) cout << "NIE" << "\n";
	else
	cout << calc_min() << ' ' << ans_max << "\n";
}
