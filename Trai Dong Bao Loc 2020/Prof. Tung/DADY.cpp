#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, string> istr;
#define For(i, a, b) for(int i = a; i <= b; i++)
#define f0(i, n) for(int i = 0; i < n; i++)
//ifstream (NAME);
//ofstream (NAME);

int n;

struct Node
{
	int k, p;
	Node *l, *r;
	Node(int key, int value)
	{
		k = key;
		p = value;
		l = r = NULL;
	}
};
typedef Node *pitem;
pitem t = nullptr;

int get_sz(Node *t)
{
	if (t == nullptr)
	return 0;
	return t->k;
}

Node *merge(Node* t1, Node* t2)
{
	if (t1 == nullptr) return t2;
	if (t2 == nullptr) return t1;
	if (t1->p > t2->p)
	{
		t1->r = merge(t1->r, t2);
		return t1;
	}
	else
	{
		t2->l = merge(t1, t2->l);
		return t2;
	}
}

void split(Node *t, int x, Node *&t1, Node *&t2)
{
	if (t == nullptr)
	{
		t1 = t2 = nullptr;
		return;
	}
	if (get_sz(t->l) < x)
	{
		split(t->r, x - get_sz(t->l) - 1, t->r, t2);
		t1 = t;
	}
	else
	{
		split(t->l, x, t1, t->l);
		t2 = t;
	}
}

void insert(int key, int value)
{
	pitem tn = new Node(key, value), t1, t2;
	split(t, key, t1, t2);
	t = merge(t1, tn);
	t = merge(t, t2);
}

int get_res(int y, int b)
{
	int ans;
	pitem t1, t2, t3, t4;
	split(t, b, t3, t4);
	t1 = t3, t2 = t4;
	if (t2 == NULL || t2->p<-y) //Khôi phục cây
	{
		t = merge(t3, t4);
		return -1;
	}
	ans = t2->k;
	while (t2 != NULL && t2->k > b)
	{
		t2 = t2->l;
		if (t2 != NULL && t2->k > -b && t2->p > -y)
			ans = t2->k;
	}
	t = merge(t3, t4);
	return ans;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("test.in", "r", stdin);
	freopen("test.ok", "w", stdout);
	int m;
	cin >> n >> m;
	while (m--)
	{
		char ch; int x, pr;
		cin >> ch >> x >> pr;
		if (ch == 'M')
		{
			insert(pr, -x);
			continue;
		}
		cout << get_res(x, pr) << "\n";
	}
}