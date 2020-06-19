#include <bits/stdc++.h>

using namespace std;

typedef int32_t ll;
#define For(i, a, b) for(ll i = a; i <= b; i++)

struct dt
{
    string name = "";
    ll solved = 0, time = 0;
    bool operator < (const dt &t)
    {
        if (solved != t.solved)
            return solved > t.solved;
        if (time != t.time)
            return time < t.time;
        return name < t.name;
    }
};

ll n, m, res;
dt team[1010];

ll parseTime(string Time)
{
    return ((Time[0] - '0') * 10 + Time[1] - '0') * 60 * 60 + 
           ((Time[3] - '0') * 10 + Time[4] - '0') * 60 + 
           ((Time[6] - '0') * 10 + Time[7] - '0');
}

void process(ll idx)
{
    ll subs;
    string task;
    team[idx] = {team[idx].name, 0, 0};
    For(i, 1, m)
    {
        cin >> task;
        if (task[0] != '-')
        {
            team[idx].solved++;
            subs = task[1] - '0';
            team[idx].time += (subs - 1) * 20 * 60 + parseTime(task.substr(3));
        }
        /* else
            team[idx].time += (task.length() > 1) ? (task[1] - '0') * 20 * 60 : 20 * 60; */
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("acm.inp", "r", stdin);
    freopen("acm.out", "w", stdout);
    cin >> n >> m;
    For(i, 1, n)
    {
        cin >> team[i].name;
        if (team[i].name == "NijeZivotJedanACM")
            res = i;
        process(i);
    }
    cin >> team[res].name;
    process(res);
    sort(team+1, team+1+n);
    /* For(i, 1, n)
    {
        cout << team[i].name << ' ' << team[i].solved  << ' ' << team[i].time << "\n";
    } */
    For(i, 1, n)
    if (team[i].name == "NijeZivotJedanACM")
    {
        cout << i << "\n";
        return 0;
    }
}