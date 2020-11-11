#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;
typedef pair<ll, string> istr;
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define f0(i, n) for(ll i = 0; i < n; i++)
//ifstream (NAME);
//ofstream (NAME);

struct Node
{
	int y, sz, val;
	Node *l, *r;
};

Node *new_node(int val)
{
	Node *result = new Node;
	result->y = rand();
	result->sz = 1;
	result->val = val;
	result->l = result->r = nullptr;
	return result;
}

Node *merge(Node* t1, Node* t2)
{
	if (t1 == nullptr) return t2;
	if (t2 == nullptr) return t1;
	if (t1->y > t2->y)
	{
		t1->r = merge(t1->r, t2);
		upd_sz(t1);
		return t1;
	}
	else
	{
		t2>l = merge(t1, t2->l);
		upd_sz(t2);
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
		split(t->r, x - get_sz(t->l) - 1, t -> r, t2);
		t1 = t;
	}
	else
	{
		split(t->l, x, t1, t->l);
		t2 = t;
	}
	upd_sz(t);
}

Node *add(Node *t, int pos, int val)
{
	Node *t1, *t2;
	split(t, pos, t1, t2);
	Node* new_tree = new_node(val);
	return merge(merge(t1, new_tree), t2);
}

Node* remove(Node *t, int pos, int num)
{
	Node *t1, *t2, *t3, *t4;
	split(t, pos, t1, t2);
	split(t2, num, t3, t4);
	t = merge(t1, t4);
	delete t3;
	return t;	
}

Node *from_vector(const vector<int>& v)
{
	Node *result = nullptr;
	f0(i, v.size())
	result = merge(result, new_node(v[i]));
	return result;
}

int get_value(Node *t, int pos)
{
	int my_idx = get_sz(t->l);
	if (pos < my_idx)
	{
		return get_value(t->l, pos);
	}
	else
	if (pos == my_idx) return t-> val;
	else
	return get_value(t->r, pos - my_idx - 1);
}

Node *to_front(Node *t, int l, int r)
{
	Node *t1, *t2, *t3, *t4;
	split(t, r+1, t1, t2);
	split(t1, l, t3, t4);
	return merge(merge(t4, t3), t2);
}

void print_tree(Node *t)
{
	if (t == nullptr) return;
	print_tree(t->l);
	cout << t->val << ' ';
	print_tree(t->r);
}

Node *cyclic_shift(Node *t, int l, int r, int k)
{
	int length = r - l + 1;
	Node *t1, *t2, *t3, *t4;
	if (k < 0) k = (length + k%length) % length;
	if (k > 0)
	{
		k %= length;
		split(t, l, t1, t2);
		split(t2, length-k, t2, t3);
		split(t3, k, t3, t4);
		t = merge(merge(merge(t1, t3), t2), t4);
	}
	return t;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<int> source_numbers(n);
	f0(i, n) cin >> source_numbers[i];
	Node *tree = from_vector(source_numbers);
	cout << "Numbers stored in the tree: " << "\n";
	f0(i, get_sz(tree))
	cout << get_value(tree, i) << ' '; cout << "\n";
	tree = cyclic_shift(tree, 1, 6, 1);
	cout << "\nCyclic Shift 1 to 6 by 1: \n";
	print_tree(tree); cout << "\n\n";
	tree = cyclic_shift(tree, 1, 5, -2);
	cout << "Cyclic Shift 1 to 5 by -2: \n";
	print_tree(tree);
	int l = 3, r = 4;
	cout << "Bring elements " << l << " thru " << r << " to front several times" << "\n";
	const int times = 2;
	f0(i, times)
	{
		tree = to_front(tree, l, r);
		cout << "Iteration " << i+1 << ", tree state: ";
		print_tree(tree);
		cout << "\n";
	}
	tree = remove(tree, 6);
	print_tree(tree);
}