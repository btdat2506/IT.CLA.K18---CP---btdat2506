#include <bits/stdc++.h>

using namespace std;
int n;
int a[100010];
int f[30001];
pair <int,int> b[30010];
void reset(){
    for (int i =1;i<=30001;i++){
        f[i]=0;
    }
}
bool cmp(pair<int,int> x, pair<int,int> y){
    return x.first < y.first;
}
void compress(){
    int coun=1;
    for (int i =1;i<=n;i++){
        a[b[i].second] = coun;
        if (b[i].first != b[i+1].first){
            coun++;
        }
    }
}
void update(int x,int val){
    while (x<=n){
        f[x] = max(val,f[x]);
        x = (x | (x + 1));
    }
}
int getres(int x){
    int res=0;
    while (x>0){
        res = max(f[x],res);
        x = (x & (x + 1)) - 1;
    }
    return res;
}
void input(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        b[i] = make_pair(x,i);
    }
    sort(b+1,b+n+1,cmp);
    compress();
}
void solve(){
    f[0]=0;
    int res=0;
    for (int i=1;i<=n;i++){
        int ma=0;
        ma = getres(a[i]-1)+1;
        update(a[i],ma);
        res = max(res,ma);

    }
    cout << res;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    reset();
    input();
    solve();
    return 0;
}
