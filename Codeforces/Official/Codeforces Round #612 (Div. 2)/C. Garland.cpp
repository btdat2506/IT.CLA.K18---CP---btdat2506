#include <bits/stdc++.h>

using namespace std;

//begin: 20:13 31/01/2019
//end:  20:51 02/02/2019

typedef int64_t ll;
typedef pair <ll, ll> pll;
#define x first
#define y second
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)

ll n, ans, amount[3];
vector <pll> same_seg, un_seg, special_case_seg; //same/unsame border segments
bool Empty[200], type[200], did_on_the_special_case_segments;

bool cmp (const pll &L, const pll &R)
{
    return (L.y - L.x + 1) < (R.y - R.x + 1);
}

void processing_same_border()
{
    //xét các dãy có border giống nhau
    for(pll v: same_seg)
    {
        ll idx = (v.x == 1) ? v.y+1 : v.x-1;
        if (amount[type[idx]] >= v.y - v.x + 1)
        {
            For(i, v.x, v.y) type[i] = type[idx];
            amount[type[idx]] -= v.y - v.x + 1;
        }
        else
        {
            ll l = v.x, r = v.y;
            r = min(v.x + (ll) amount[(ll) !type[idx]], v.y);
            For(i, v.x, r) type[i] = !type[idx];
            amount[!type[idx]] = 0;
            if (r != v.y)
            {
                For(i, r+1, v.y) type[i] = type[idx];
                amount[type[idx]] -= v.y - r+1 + 1;
            }
            //ans += 2;
        }
    }
}

void processing_unsame_border()
{
    //xét các dãy có border khác nhau
    //nếu đủ thì điền hết nguyên dãy 1 cái
    //còn không thì chia ra điền 1 bên 1 cái, cái còn lại điền bên kia
    for(pll v: un_seg)
    {
        bool choice = (amount[0] > amount[1]) ? 0 : 1;
        if (amount[choice] >= v.y - v.x + 1)
        {
            For(i, v.x, v.y) type[i] = choice;
            amount[choice] -= v.y - v.x + 1;
        }
        else
        {
            ll l = v.x, r = v.y;
            if (type[r+1] == choice)
            {
                Fod(i, r, r-amount[choice]) type[i] = choice;
                For(i, l, r-amount[choice]-1) type[i] = !choice;
            }
            else
            {
                For(i, l, l+amount[choice]) type[i] = choice;
                For(i, l+amount[choice]+1, r) type[i] = !choice;
            }
            amount[!choice] = r - l + 1 - amount[choice];
            amount[choice] = 0;
        }
        //ans += 1;
    }
}

void debug()
{
    cout << "Debugging" << "\n";
    cout << amount[0] << ' ' << amount[1] << "\n\n";
    for(pll v: same_seg)
    cout << v.x << ' ' << v.y << ' ' << type[v.y+1] << "\n"; cout << "\n";
    for(pll v: special_case_seg)
    cout << v.x << ' ' << v.y << ' ' << type[v.y+1] << "\n"; cout << "\n";
    for(pll v: un_seg)
    cout << v.x << ' ' << v.y << ' ' << type[v.y+1] << "\n"; cout << "\n";
    cout << "End debugging!" << "\n";
}

void pre_processing()
{
    //gán type[0] và type[n+1] với thằng gần nhất để tiện xử lí
    Empty[0] = Empty[n+1] = 1;
    for(ll i = 1; i <= n && Empty[0]; i++)
    if (!Empty[i])
        Empty[0] = 0,
        type[0] = type[i];
    for(ll i = n; i >= 1 && Empty[n+1]; i--)
    if (!Empty[i])
        Empty[n+1] = 0,
        type[n+1] = type[i];
    // đưa các đoạn trống vào hậu xử lí
    for(ll i = 1, j = 1; i <= n && j <= n;)
    {
        while (!Empty[i] && i <= n) i++; j = i + 1;
        while  (Empty[j] && j <= n) j++;
        if (i > n || j > n+1) break;
        if (i == 1 || j > n)
            special_case_seg.push_back(pll(i, j-1)); else
        if (type[i-1] == type[j])
            same_seg.push_back(pll(i, j-1));
        else
            un_seg.push_back(pll(i, j-1));
        i = j;
    }
    //debug();
    //sắp xếp lại tăng dần về độ dài để tối thiểu số lượng hao hụt
    sort(same_seg.begin(), same_seg.end(), cmp);
    sort(special_case_seg.begin(), special_case_seg.end(), cmp);
    sort(un_seg.begin(), un_seg.end(), cmp);
}

ll complexity_of_special_case_segments(pll v)
{
    //Đã fix: quên xét trường hợp nếu l = 1 hoặc r = n
    //đpt sẽ hoặc là 0 hoặc 1
    ll idx = (v.x == 1) ? v.y+1 : v.x-1;
    if (amount[type[idx]] >= v.y - v.x + 1)
    {
        amount[type[idx]] -= v.y - v.x + 1;
        return 0;
    }
    else
    {
        ll l = v.x, r = v.y;
        r = min(v.x + (ll) amount[(ll) !type[idx]], v.y);
        amount[!type[idx]] = amount[!type[idx]] - (r - l + 1);
        if (r != v.y)
        amount[type[idx]] -= v.y - r+1 + 1;
        return 1;
    }
}

ll complexity_of_same_border(pll v)
{
    ll idx = (v.x == 1) ? v.y+1 : v.x-1;
    if (amount[type[idx]] >= v.y - v.x + 1)
    {
        amount[type[idx]] -= (v.y - v.x + 1);
        return 0;
    }
    else
    {
        if (!did_on_the_special_case_segments)
        for(pll t: special_case_seg)
        ans += complexity_of_special_case_segments(t),
        did_on_the_special_case_segments = 1;
        ll l = v.x, r = v.y;
        r = min(v.x + (ll) amount[(ll) !type[idx]] - 1, v.y);
        amount[!type[idx]] = amount[!type[idx]] - (r - l + 1);
        if (r < v.y)
        amount[type[idx]] -= v.y - r;
        return 2;
    }
}

ll complexity_of_not_same_border(pll v)
{
    bool choice = (amount[0] > amount[1]) ? 0 : 1;
    if (amount[choice] >= v.y - v.x + 1)
    {
        For(i, v.x, v.y) type[i] = choice;
        amount[choice] -= v.y - v.x + 1;
    }
    else
    {
        ll l = v.x, r = v.y;
        amount[choice] = (r - l + 1) - amount[choice];
        amount[!choice] = amount[!choice] - ((r - l + 1) - amount[choice]);
    }
    return 1;
    //mảng amount đánh dấu số lượng sai
}

void calculate_complexity()
{
    For(i, 2, n)
    if (!Empty[i] && !Empty[i-1])
    {
        ans += ((ll) type[i] + (ll) type[i-1]) % 2;
    }
    //cout << ans << "\n";
    //cout << amount[0] << ' ' << amount[1] << "\n";
    for(pll v: same_seg)
    {
        ll tmp = complexity_of_same_border(v);
        if (tmp > 0) 
        {
            //cout << 'x' << ' ' << v.x << ' ' << v.y << ' ' << type[v.x-1] << "\n";
            ans += tmp;
        }
    }
    //cout << amount[0] << ' ' << amount[1] << "\n";
    //ans += complexity_of_same_border(v);
    //đã fix: xét thiếu trường hợp đặc biệt
    /* for(pll v: special_case_seg)
    {
        ll tmp = complexity_of_special_case_segments(v);
        cout << v.x << ' ' << v.y << ' ' << tmp << "\n";
        cout << amount[0] << ' ' << amount[1] << "\n";
        ans += tmp;
    } cout << "\n"; */
    if (!did_on_the_special_case_segments)
    for(pll v: special_case_seg)
    ans += complexity_of_special_case_segments(v);
    for(pll v: un_seg)
    {
        ans += complexity_of_not_same_border(v);
        //cout << v.x << ' ' << v.y << ' ' << "\n";
    }
    //ans += complexity_of_not_same_border(v);
}

void process()
{
    //LƯU Ý: Mới chỉ fix trong cái calculate complexity
    //các processing border chưa được fix bugs
    if (n == 1)
    {
        cout << 0 << "\n";
        return;
    }
    pre_processing();
    //processing border là thay thế các số vào các ô trống rồi sau đó tính
    /* processing_same_border();
    processing_unsame_border(); */
    //calculate complexity là tính sẵn độ phức tạp hiện tại của dãy đã có 
    //rồi sau đó tuân theo quy luật độ phức tạp của 2 viền:
    //nếu viền giống nhau: +0 hoặc +2
    //nếu viền khác nhau: luôn +1
    calculate_complexity();
    //For(i, 1, n-1)
    //ans += (((ll) type[i] + (ll) type[i+1]) % 2 == 0) ? 0 : 1;
    //cout << amount[0] << ' ' << amount[1] << "\n";
    cout << ans << "\n";
}

void input()
{
    ll tmp;
    cin >> n;
    amount[0] = amount[1] = n / 2;
    amount[1] = (n % 2) ? amount[1] + 1 : amount[1];
    For(i, 1, n)
    {
        cin >> tmp;
        if (tmp == 0) 
            Empty[i] = 1;
        else
            type[i] = tmp % 2,
            amount[type[i]]--;
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("test.in", "r", stdin);
    freopen("test.ok", "w", stdout);
    input();
    process();
}