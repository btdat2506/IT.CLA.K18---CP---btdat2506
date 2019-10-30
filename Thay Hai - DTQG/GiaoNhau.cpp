#include <bits/stdc++.h>
using namespace std;

struct data {
    int64_t x1, x2, y1, y2;
};

const int64_t nmax = 1000;

int64_t n;
data dl[nmax];

void Input() {
    cin >> n;
    for (int64_t i = 0; i < n; i++) {
        cin >> dl[i].x1 >> dl[i].y1 >> dl[i].x2 >> dl[i].y2;
    }
}

void Process() {
    for (int64_t i = 0; i < n-1; i++)
    for (int64_t j = i+1; j < n; j++) {
        if ((dl[i].x1 - dl[i].x2)*(dl[j].y1 - dl[j].y2) - (dl[i].y1 - dl[i].y2)*(dl[j].x1 - dl[j].x2) > 0)
            cout << "Duong thang " << i+1 << " cat duong thang " << j+1 << endl;
    }
}

int main() {
    freopen("in.inp", "r", stdin);
    Input();
    Process();
}
