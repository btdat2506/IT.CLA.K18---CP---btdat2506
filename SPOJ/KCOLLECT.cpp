#include <bits/stdc++.h>

using namespace std;

typedef int ll;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
#define x first
#define y second
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

const ll N = 110, M = 10100;
ll m, n, num[N][N], weight[M]; //num: number of scc that they belong to in a condensation graph
bool used[N][N];                    //use to mark visited in input
char db[N][N];                      //input
ii step[2] = {{0, 1}, {1, 0}};      //use for dfs
vii order, component;               //use for condensation graph
ll Num, d[M], visited[M];          //number of vertices, visited vertices
vi edge[M];                  //edge in graph
ll p[M], pos; //parent, for debug

/* 
    bug1 (if bug2 is fixed, than bug1 will no longer be an issue since bug1 only exists if only the property of bug2 wasn't resolved):
    khi để step xuống hàng rồi mới sang phải, với code ver1 sẽ bị bug mất 1 cạnh của đồ thị

    bug2: because of the reversed graph property, the case of adjacent vertex that has "W" or "N" is also need to be consider 
    as for the reversed edge property, the adjacent vertex won't be able to have 
    the ability of see the reversed edge if the adjacent vertex wasn't consider  

    bug3: direction when only down, right, "#" and "N"
    1st version of code: the first dfs only starts at (1, 1), which leaves disconnected nodes didn't visited, 
    so after the topo sort of the 1st dfs, the order will leaves disconnected nodes in the ability of letting "visited" 
    when the graph is reversed in the 2nd dfs when the code needs to find the SCCs.

    resolved for bug3: 
    - On the 1st dfs (which functions as topo sort), don't visit only node (1, 1), visit every nodes that are not visited, starts with (1, 1)
    - After that, start longest path from the number of node (1, 1) because the customized of 1st dfs has made the number of node (1, 1) no longer be "1", 
    so we need to take the number that it was assigned to traverse in the longest path

*/

void dfs1(ll i, ll j) //follow the rules of the problem
{
    used[i][j] = 1;
    for(ii t: step)
    if (i + t.x <= m && j + t.y <= n)
    {
        if (!used[i + t.x][j + t.y] && db[i + t.x][j + t.y] != '#')
        dfs1(i + t.x, j + t.y);
    }
    if (db[i][j] == 'W' && !used[i][j - 1] && db[i][j - 1] != '#' && j - 1 >= 1)
        dfs1(i, j - 1);
    if (db[i][j] == 'N' && !used[i - 1][j] && db[i - 1][j] != '#' && i - 1 >= 1)
        dfs1(i - 1, j);
    order.push_back(ii(i, j));
}

void dfs2(ll i, ll j) //reversed of dfs1
{
    used[i][j] = 1;
    component.push_back(ii(i, j));
    for(ii t: step)
    if (i - t.x > 0 && j - t.y > 0)
    {
        if (!used[i - t.x][j - t.y] && db[i - t.x][j - t.y] != '#')
        dfs2(i - t.x, j - t.y);
    }
    if (db[i][j + 1] == 'W' && !used[i][j + 1] && db[i][j + 1] != '#' && j + 1 <= n)
        dfs2(i, j + 1);
    if (db[i + 1][j] == 'N' && !used[i + 1][j] && db[i + 1][j] != '#' && i + 1 <= m)
        dfs2(i + 1, j);
}

void test_graph()
{
    For(i, 1, m)
    {
        For(j, 1, n)
        cout << num[i][j] << ' ';
        cout << "\n";
    }
}

void create_condensation_graph()
{
    For(i, 1, m)
    For(j, 1, n)
    if (!used[i][j] && db[i][j] != '#')
        dfs1(i, j);
    memset(used, 0, sizeof(used));
    Num = 0;
    Fod(i, order.size()-1, 0)
    {
        ll a = order[i].x, b = order[i].y;
        if (!used[a][b])
        {
            //cout << a << ' ' << b << "\n";
            dfs2(a, b);
            Num++;
            for(ii t: component)
                num[t.x][t.y] = Num;
            component.clear();
        }
    }
    //test_graph();
}

void calculate_value_vertex()
{
    For(i, 1, m)
    For(j, 1, n)
    {
        if ('0' <= db[i][j] && db[i][j] <= '9')
        weight[num[i][j]] += db[i][j] - '0';
    }
}

void create_graph()
{
    For(i, 1, m)
    For(j, 1, n)
    {
        for(ii t: step)
        if (i + t.x <= m && j + t.y <= n && db[i + t.x][j + t.y] != '#')
        {
            if (num[i][j] != num[i + t.x][j + t.y])
            edge[num[i][j]].push_back(num[i + t.x][j + t.y]);
        }
        if (db[i][j] == 'W' && !used[i][j + 1] && db[i][j + 1] != '#' && j + 1 <= n)
        {
            if (num[i][j] != num[i][j + 1])
            edge[num[i][j]].push_back(num[i][j + 1]);
        }
        if (db[i][j] == 'N' && !used[i + 1][j] && db[i + 1][j] != '#' && i + 1 <= m)
        {
            if (num[i][j] != num[i + 1][j])
            edge[num[i][j]].push_back(num[i + 1][j]);
        }
    }
}

void dfs_tpsort(ll u, stack <ll> &temp)
{
    visited[u] = 1;
    for(ll v: edge[u])
    if (!visited[v])
    dfs_tpsort(v, temp);
    temp.push(u);
}

stack <ll> topo_sort()
{
    stack <ll> temp;
    /*For(i, 1, Num)
    if (!visited[i]) */
    dfs_tpsort(num[1][1], temp);
    memset(visited, 0, sizeof(visited));
    return temp;
}

void debug02()
{
    For(i, 1, Num)
    cout << d[i] << ' '; cout << "\n";
    for(ll t = pos; t != 0; t = p[t])
    cout << t << ' '; cout << "\n";
}

void longest_path()
{
    stack <ll> tp = topo_sort();
    //viết hàm dfs tính đường đi dài nhất có được (xét trường hợp vị trí của các đích, multi end)
    d[tp.top()] = weight[tp.top()];
    p[tp.top()] = 0;
    while (!tp.empty())
    {
        ll u = tp.top(); tp.pop();
        for(ll v: edge[u])
        if (d[v] < d[u] + weight[v])
            d[v] = d[u] + weight[v],
            p[v] = u;
    }
    ll ans = 0;
    For(i, 1, Num) 
        ans = max(ans, d[i]), 
        pos = i;
    //debug02();
    cout << ans << "\n";
}

void process()
{
    create_condensation_graph();
    calculate_value_vertex();
    create_graph();
    longest_path();
}

void input()
{
    cin >> m >> n;
    For(i, 1, m)
    For(j, 1, n)
    cin >> db[i][j];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    input();
    process();
}