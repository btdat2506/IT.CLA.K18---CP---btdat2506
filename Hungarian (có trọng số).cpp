#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

typedef long long llint;
const int maxN=1000+10,maxQ=maxN*maxN;
typedef pair<int,int> II;
#define fs first
#define sd second
#define MP make_pair
#define PB push_back
#define FORE(it,c) for(typeof(c.begin())it=c.begin();it!=c.end();it++)

int n,m;
llint d[maxN][maxN];
vector<II> a[maxN];
II qu[maxQ];
int top,bot;
bool inq[maxN][maxN];

int main(){
    freopen("tours.inp","r",stdin);
    freopen("tours.out","w",stdout);
    memset(d, 0, sizeof d);
    cin >> n >> m;
    ll u, v, c;
    top=0; bot=1;
    for (int i=0;i<m;i++){
        scanf("%d%d%d",&u,&v,&c);
        a[u].PB(MP(v,c));
        d[u][v]=c;
        inq[u][v]=true;
        qu[++top]=MP(u,v);
    }

    //printf("bot=%d,top=%d\n",bot,top);

    while (bot<=top){
        II u=qu[(bot++)%maxQ];
        llint D=d[u.fs][u.sd]; inq[u.fs][u.sd]=false;
        FORE (it,a[u.sd]) if (d[u.fs][it->fs]>D+it->sd){
            d[u.fs][it->fs]=D+it->sd;
            if (!inq[u.fs][it->fs]){
                inq[u.fs][it->fs]=true;
                qu[(++top)%maxQ]=MP(u.fs,it->fs);
            }
        }
    }

    for (int i=1;i<=n;i++){
        if (d[i][i]>=d[0][0]) printf("-1\n");
        else cout<<d[i][i]<<endl;
    }
    fprintf(stderr,"Top=%d\n",top);
    return 0;
}