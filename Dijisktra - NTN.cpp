#include <bits/stdc++.h>                                                                                                
#define pp pair<int,int>
using namespace std;
vector <pp> a[1001];
int n,m,k,v;
int we[1001],fre[1001],trace[1001];

void reset(){
    for (int i =0;i<=1000;i++){
        we[i] = 1e9;fre[i]=false;
        trace[i]=0;
    }
}

void dj(int u){
   we[u] = 0;
    while (true){
        u =0;
        for (int i =1;i<=n;i++){
            if (we[i]<we[u] && fre[i]) u=i;
        }
        if (u==0 || u ==v) return;
        fre[u] = false;
        for (auto i:a[u]){
            if (we[i.second] > we[u] + i.first ){
                trace[i.second]=u;
                we[i.second] = we[u] +i.first;
            }
        }
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for (int i =1;i<=m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        a[x].push_back(make_pair(z,y));
        a[y].push_back(make_pair(z,x));
    }
    for (int o=0;o<k;o++){
        int check,u,v;
        scanf("%d%d%d",&check,&u,&v);
        reset();
        dj(u);
        if (!check){
            cout << we[v] << endl;
        }else{
            vector <int> tr;
            while (v!=0){
                tr.push_back(v);
                v=trace[v];
            }
            cout << tr.size()<< ' ';
            for (int i=tr.size()-1;i>=0;i--) cout << tr[i] << ' ' ;
            cout << endl;
        }
    }
    return 0;
}
