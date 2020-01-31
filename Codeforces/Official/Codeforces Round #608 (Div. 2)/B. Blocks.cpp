#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

ll n, b, w, res, ans[300], arr[300], cnt[2];

bool ok()
{
    For(i, 1, n)
    if (arr[i] == 0) b++; else w++;
    if (b % 2 && w % 2)
        return 0;
    else
        return 1;
}

void rotate(ll color)
{
    For(i, 1, n-1)
    if (arr[i] == arr[i+1] && arr[i] == color)
        cnt[color] -= 2,
        arr[i] = arr[i+1] = (color + 1) % 2,
        ans[++res] = i;
    else
    if (arr[i] != arr[i+1] && arr[i] == color)
    {
        swap(arr[i], arr[i+1]);
        ans[++res] = i;
    }
}

void process()
{
    if (!ok())
    {
        cout << -1 << "\n";
        return;
    }
    if (b % 2) while (b) rotate(0); else
    if (w % 2) while (w) rotate(1);
    cout << res << "\n";
    For(i, 1, res)
    cout << ans[i] << " ";
}

void input()
{
    cin >> n;
    char ch;
    For(i, 1, n)
    {
        cin >> ch;
        arr[i] = (ch == 'B') ? 0 : 1;
    } 
}

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    input();
    process();
}

//cd "/Volumes/Data/IT.CLA.K18 - btdat2506/Codeforces Round #608 (Div. 2)/" 
//&& g++ B. Blocks.cpp -o B. Blocks 
//&& "/Volumes/Data/IT.CLA.K18 - btdat2506/Codeforces Round #608 (Div. 2)/"B. Blocks