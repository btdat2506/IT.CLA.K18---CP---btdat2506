#include <bits/stdc++.h>
using namespace std;

struct data {
    int64_t x, y;
};

int64_t n;
data dl[1000], p1, p2;

void Input() {
    cin >> n;
    for (int64_t i = 0; i < n; i++) {
        cin >> dl[i].x >> dl[i].y;
        p2.x = max(p2.x, dl[i].x);

    }
    cin >> p1.x >> p1.y;
}

int64_t Calc(data p, data p1, data p2) {
    return (p2.y - p1.y)*p.x + (p1.x - p2.x)*p.y + (p2.x*p1.y - p1.x*p2.y);
}

int64_t Check(data p1, data p2, data p3, data p4) {
    int64_t t1 = Calc(p1, p3, p4), t2 = Calc(p2, p3, p4);
//    cout << t1 << " " << t2 << "<";
    if (t1 == 0 && t2 == 0) return 2;
    if (t1*t2 > 0) return 0;
    if (t1*t2 < 0) return 1;
    return 3;
}

void Process() {
    int64_t res = 0;
    bool kt = false;
    p2.y = p1.y;
    p2.x = max(p2.x, p1.x); p2.x++;
    cout << p1.x << " " << p1.y << " " << p2.x << " " << p2.y << endl;
//    cout << dl[1].x << " " << dl[1].y << " " << Check(dl[0], dl[1], p1, p2) << endl;
    for (int64_t i = 0; i < n; i++) {
        if (i < n-1 && Calc(p1, dl[i], dl[i+1]) == 0) kt = true;
        else if (Calc(p1, dl[0], dl[n-1]) == 0) kt = true;
    }
    if (!kt) {
    for (int64_t i = 0; i < n; i++)
        if (Calc(dl[i], p1, p2) == 0) {
            if (i == 0 && Check(dl[1], dl[n-1], p1, p2) == 1) res++;
            if (i == n-1 && Check(dl[0], dl[n-2], p1, p2) == 1) res++;
            if (i != 0 && i != n-1 && Check(dl[i-1], dl[i+1], p1, p2) == 1) res++;
//            cout << "<" << i << " " << res << "> ";
        }
//    cout << res << endl;
    for (int64_t i = 0; i < n; i++) {
        if (i == n-3 && Check(dl[i], dl[0], p1, p2) == 1 && Check(dl[i+1], dl[i+2], p1, p2) == 2) res++;
        if (i == n-2 && Check(dl[i], dl[1], p1, p2) == 1 && Check(dl[i+1], dl[0], p1, p2) == 2) res++;
        if (i == n-1 && Check(dl[i], dl[2], p1, p2) == 1 && Check(dl[1], dl[0], p1, p2) == 2) res++;
        if (i < n-3 && Check(dl[i], dl[i+3], p1, p2) == 1 && Check(dl[i+1], dl[i+2], p1, p2) == 2) res++;
    }
//    cout << res << endl;
    for (int64_t i = 0; i < n; i++) {
        if (i < n && Check(dl[i], dl[i+1], p1, p2) == 1 && Check(p1, p2, dl[i], dl[i+1]) == 1) res++;
        else if (Check(dl[i], dl[0], p1, p2) == 1 && Check(p1, p2, dl[i], dl[i+1]) == 1) res++;
//            cout << "<" << i << " " << res << "> ";
    } }
//    cout << res << endl;
    if (res % 2 == 1 || kt) cout << "Thuoc";
    else cout << "Khong Thuoc";
}

int main()
{
//    freopen("in.inp", "r", stdin);
    Input();
    Process();
}
