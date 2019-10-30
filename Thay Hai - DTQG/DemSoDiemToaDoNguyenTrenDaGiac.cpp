#include <bits/stdc++.h>
using namespace std;

struct point {
    int64_t x, y;
};

const int64_t nmax = 10010;

int64_t n;
point p[nmax];

void Input() {
    cin >> n;
    for (int64_t i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
}

int64_t gcd(int64_t a, int64_t b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

void Process() {
    float a = 0, b = 0;
    for (int64_t i = 1; i < n; i++)
        a += (p[i].x - p[i-1].x)*(p[i].y - p[i-1].y);
    a += (p[1].x - p[n-1].x)*(p[1].y - p[n-1].y);
    for (int64_t i = 1; i < n; i++)
        b += gcd(p[i].x - p[i-1].x, p[i].y - p[i-1].y);
    b += gcd(p[1].x - p[n-1].x, p[1].y - p[n-1].y);
    cout << a << " " << b << endl;    cout << round(abs(a/2) + b/2 + 1);
}

int main()
{
    Input();
    Process();
}
