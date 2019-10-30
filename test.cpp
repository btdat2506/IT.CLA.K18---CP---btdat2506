#include <bits/stdc++.h>

int T[10230997];
int n, m;

int max(int a, int b){ return a>b?a:b; }

int query(int node, int ll, int rr, int u, int v){
    if (v<ll or rr<u or ll>rr) { return -1000111000; }
    if (u<=ll and ll<=rr and rr<=v) return T[node];
    return max(
        query(node*2, ll, (ll+rr)/2, u, v),
        query(node*2+1, (ll+rr)/2+1, rr, u, v)
    );
}

void update(int node, int ll, int rr, int i, int v){
    if (i<ll or i>rr or ll>rr) return;
    if (ll!=rr){
        update(node*2, ll, (ll+rr)/2, i, v);
        update(node*2+1, (ll+rr)/2+1, rr, i, v);
        T[node] = max(T[node*2], T[node*2+1]);
    }
    else T[node] = v;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int p, q; char c;
    scanf("%d%d", &n, &m);
    while (m--){
        scanf(" %c%d%d", &c, &p, &q);
        if (c=='u' or c=='U') update(1, 1, n, p, q);
        if (c=='q' or c=='Q') printf("%d\n", query(1, 1, n, p, q));
    }
    for(int i = 1; i <= 25; i++) std::cout << T[i] << std::endl;
}