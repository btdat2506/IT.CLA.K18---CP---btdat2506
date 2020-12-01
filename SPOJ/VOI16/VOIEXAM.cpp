#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef <int, ll> ii;
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define f0(i, b) for(ll i = 0; i < b; i++)

ll n;
vector <ii> db[2010];
vector <ll> edge[2010];
set <ll> res[2010]; //calculated values

ll get_val(ll num1, char op1, ll num2)
{
	if (op1 == '+') return num1 + num2;
	if (op1 == '-') return num1 - num2;
	if (op1 == '*') return num1 * num2;
}

ll get_val(ll num1, char op1, ll num2, char op2, ll num3)
{
	ll t = num1;
	if (op1 == '+') t += num2;
	if (op1 == '-') t -= num2;
	if (op1 == '*') t *= num2;
	
	if (op2 == '+') t += num3;
	if (op2 == '-') t -= num3;
	if (op2 == '*') t *= num3;
	return t;
}

ll get_val(ll num1, char op1, ll num2, char op2, ll num3, char op3, ll num4)
{
	ll t = num1;
	if (op1 == '+') t += num2;
	if (op1 == '-') t -= num2;
	if (op1 == '*') t *= num2;
	
	if (op2 == '+') t += num3;
	if (op2 == '-') t -= num3;
	if (op2 == '*') t *= num3;
	return t;
}

ll T(ll num1, char op1, ll num2)
{
	return get_val(num1, op1, num2);
}

void process()
{
	For(i, 1, n)
	{
		ll num[4]; char op[4]; ll cnt_op;
		tie(cnt_op, num, op) = db[i];
		if (cnt_op == 1)
		{
			res[i].insert(get_val(num[0], op[0], num[1]);
		}
		if (cnt_op == 2)
		{
			res[i].insert(get_val(T(num[0], op[0], num[1]), op[1], num[2]));
			res[i].insert(get_val(num[0], op[0], T(num[1], op[1], num[2])));
		}
		if (cnt_op == 3)
		{
			res[i].insert(get_val(T(num[0], op[0], num[1]), op[1], num[2], op[2], num[3]));
			res[i].insert(get_val(num[0], op[0], T(num[1], op[1], num[2]), op[2], num[3]));
			res[i].insert(get_val(T(num[0], op[0], T(num[1], op[1], num[2])), op[2], num[3]));
			res[i].insert(get_val(num[0], op[0], T(num[1], op[1], T(num[2], op[2], num[3]))));
		}
	}
}

void input()
{
	string st;
	ll num[4], cnt_op;
	vector <string> inp;
	cin >> n;
	For(i, 1, n)
	{
		cnt_op = 0;
		memset(num, 0, sizeof(num));
		memset(op, '.', sizeof(op));

		cin >> st;
		for(char c: st)
		if ('0' <= c && c <= '9')
		{
			num[cnt_op] = num[cnt_op] * 10 + (c - '0');
		}
		else
		{
			op[cnt_op] = c;
			cnt_op++;
		}
		db[i].num = copy(num, num+cnt_op);
		db[i].op = copy(op, op+cnt_op);
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("test.in", "r", stdin);
	freopen("test.ok", "w", stdout);
	input();
	process();
}


/* 
//bài học về việc không tối ưu code


vector <ll> bfs(ll t)
{
	queue <ii> qu;
	f0(i, n)
	qu.push(ii(1 << (i - 1), 0)); //(state, pos); state from 0 to (1 << n) - 1
	while (!qu.empty())
	{
		ll state = qu.top().first, du = qu.top().second;
		qu.pop();
		if (state == (1 << n) - 1)
		{
			res[t].insert(u);
			continue;
		}
		f0(i, n)
		if (!((1 << (i - 1)) & state))
		{
			du = 
		}
	}
}

vector <ii> convert_inp(string st)
{
	ll len = st.size();
	vector <ii> t;
	queue <ii> qu;

	f0(i, n)
	if (st[i] == '+' || st[i] == '-' || st[i] == '*')
	{
		ll p;
		if (st[i] == '+') p = 1;
		if (st[i] == '-') p = 2;
		if (st[i] == '*') p = 3;
		qu.push(ii(i, -1));
	}

	ll pos = 0;
	while (!qu.empty())
	{

		ll p = 0, num = 0;
		if (st[qu.top().second] == '+') p = 1;
		if (st[qu.top().second] == '-') p = 2;
		if (st[qu.top().second] == '*') p = 3;

		For(i, pos, qu.top().first - 1)
		{
			num = num * 10 + (st[i] - '0');
		}
		pos = qu.top().first + 1;

		t.push_back(ii(p, num));
		qu.pop();
	}
	return t;
} */