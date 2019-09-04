#include <bits/stdc++.h>

using namespace std;
#define For(i, a ,b) for(int64_t i = a; i <= b; i++)
#define FOD(i,r,l) for (int64_t i=r;i>=l;i--)
#define ll int64_t
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define ep emplace_back
#define EL cout << endl
#define sz(A) (int) A.size()
#define fillchar(a,x) memset(a, x, sizeof (a))
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

ll t, n;
string st;

bool nine()
{
   For(i, 0, n-1) if (st[i] != '9') return 0;
   cout << 1;
   For(i, 1, n-1) cout << 0;
   cout << 1 << endl;
   return 1;
}

ll init()
{
   return (n % 2 == 0) ? n / 2 - 1 : n / 2;
}

void process()
{
   ll i = init(), j = n / 2, temp = 1, num = 1;
   while (i >= 0 && st[i] == st[j]) 
   i--, j++;
   if (i < 0 || st[i] < st[j])
   {
      i = init(), j = n / 2;
      while (i >= 0)
      {
         num = (st[i] - '0') + temp;
         temp = num / 10;
         st[i] = (num % 10) + '0';
         st[j] = st[i];
         i--;
         j++;
      }
   }
   else
   while (i >= 0)
   {
      st[j] = st[i];
      i--;
      j++;
   }
   cout << st << endl;
}

int main()
{
   faster
   cin >> t;
   For(dem, 1, t)
   {
      cin >> st;
      n = st.length();
      if (!nine()) process();
   }
   return 0;
}