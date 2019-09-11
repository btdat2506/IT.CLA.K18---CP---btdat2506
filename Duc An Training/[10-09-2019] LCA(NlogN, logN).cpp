#include <bits/stdc++.h>

using namespace std;

#define ll int64_t
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

void pre_process(int N, int T[MAXN], int P[MAXN][LOGMAXN])
{
  int i, j;

  // Khởi tạo
  for (i = 0; i < N; i++)
    for (j = 0; 1 << j < N; j++)
      P[i][j] = -1;

  // Khởi tạo cha thứ 2^0 = 1 của mỗi nút
  for (i = 0; i < N; i++)
    P[i][0] = T[i];

  // Quy hoạch động
  for (j = 1; 1 << j < N; j++)
    for (i = 0; i < N; i++)
      if (P[i][j - 1] != -1)
        P[i][j] = P[P[i][j - 1]][j - 1];
}

ll LCA()
{
	if (h(u) < h(v))
    // Đổi u và v
    swap(u, v);

  log = log2( h(u) );

  // Tìm tổ tiên u' của u sao cho h(u') = h(v)

  Fod(i, log, 0):
    if (h(u) - 2^i >= h(v))
      u = P[u][i];

  if (u == v)
    return u

  // Tính LCA(u, v):
  for i = log .. 0:
    if P[u][i] != -1 and P[u][i] != P[v][i]:
      u = P[u][i]
      v = P[v][i]

  return T[u];
}
  
void process()
{

}

void input()
{
	cin >> n;
	For(i, 1, n)
	{
		ll m;
		cin >> m;
		For(j, 1, m)

	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ll t;
	cin >> t;
	while (t--)
	{	
		input();
		process();
	}
}