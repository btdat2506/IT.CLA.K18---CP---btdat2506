#include <bits/stdc++.h>
using namespace std;
#define For(x, y, z) for(int64_t x = y; x <= z; x++)
int64_t s = 0; 
bool arr[1100][1100];
int m, n, k, res = 0;

bool process1(int64_t x, int64_t y, int64_t r, int64_t h)
{
    int xa, xb, xc, xd, ya, yb, yc, yd;
    int xh = x, yh = y - h, 
    xb = xh + h, yb = yh + r, 
    xc = xb + r, yc = yb + r - h, 
    xd = xc + r - h, yd = yc;
    if (arr[xh][yh] && arr[xb][yb] && arr[xc][yc] && arr[xd][yd]) return 1; else return 0;
}

bool process2(int64_t x, int64_t y, int64_t r, int64_t h)
{
    int xa, xb, xc, xd, ya, yb, yc, yd;
    int xh = x, yh = y - h, 
    xb = xb + r, yb = yb + r - h, 
    xc = xh + h, yc = yh + r, 
    xd = xc + r - h, yd = yc;
    if (arr[xh][yh] && arr[xb][yb] && arr[xc][yc] && arr[xd][yd]) return 1; else return 0;
}

bool process3(int64_t x, int64_t y, int64_t r, int64_t h)
{
    int xa, xb, xc, xd, ya, yb, yc, yd;
    int xh = x, yh = y - h, 
    xb = xh + h, yb = yh + r, 
    xc = xb + r - h, yc = yb, 
    xd = xc + r, yd = yc + r - h;
    if (arr[xh][yh] && arr[xb][yb] && arr[xc][yc] && arr[xd][yd]) return 1; else return 0;
}

bool process4(int64_t x, int64_t y, int64_t r, int64_t h)
{
    int xa, xb, xc, xd, ya, yb, yc, yd;
    int xh = x, yh = y - h, 
    xb = xh + r - h, yb = yh, 
    xc = xb + r, yc = yb + r - h, 
    xd = xc + h, yd = yc + r;
    if (arr[xh][yh] && arr[xb][yb] && arr[xc][yc] && arr[xd][yd]) return 1; else return 0;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("SQUARES.INP", "r", stdin);
    freopen("SQUARES.OUT", "w", stdout);
    cin >> m >> n >> k;
    memset(arr, 1, sizeof(arr));
    For(i, 1, k)
    {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 0;
    }
    int xa, xb, xc, xd, ya, yb, yc, yd, hx, hy;
    For(r, 1, min(m, n) - 1)
    res += r*(m - r)*(n-r);
    For(dem, 1, k)
    {
        xa = x[dem], ya =   y[dem];
        For(x, 1, min(m, n) - 1)
        For(h, 0, r-1)
        {
            if (process1(xa, ya, x, h) == 0) res--;
            if (process2(xa, ya, x, h) == 0) res--;
            if (process3(xa, ya, x, h) == 0) res--;
            if (process4(xa, ya, x, h) == 0) res--;
        }
    }
    cout << res;
    return 0;
}



/* Subtask 1 2 3:
if (k == 0) 
    {
        For(r, 1, min(m, n) - 1)
        res += r*(m - r)*(n-r);
    }
    else
    {
        For(r, 1, min(m, n) - 1)
        For(x, 1, m-r)
        For(y, 1, n-r)
        For(h, 0, r - 1)
        res += process(x, y, r, h);
    }


    bool process(int64_t x, int64_t y, int64_t r, int64_t h)
{
    int xa, xb, xc, xd, ya, yb, yc, yd;
    xa = x, ya = y + h, 
    xb = x + h, yb = y + r, 
    xc = x + r, yc = y + r - h, 
    xd = x + r - h, yd = y;
    if (arr[xa][ya] && arr[xb][yb] && arr[xc][yc] && arr[xd][yd]) return 1; else return 0;
}
*/

/* Do phải suggest các điểm còn lại từ điểm A để loại trừ các trường hợp không tồn tại hình vuông nên phải swap các vị trí với nhau để tìm ra các điểm còn lại từ r(r cách một đoạn từ điểm a đến hình vuông tượng trưng song song với giá) do nếu phán đoán r thì sẽ tạo ra những hình vuông không phù hợp, có thể dẫn đến bị lọt ra khỏi lưới */