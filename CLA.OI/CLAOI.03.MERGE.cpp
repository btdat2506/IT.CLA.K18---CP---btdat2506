#include <bits/stdc++.h>

using namespace std;
#define For(i, a, b) for(int64_t i = a; i < b; i++)
int64_t n1, n2;
/*vector <vector <int64_t>> in;

bool switch_n(int64_t stt_n1, int64_t stt_n2)
{
    if (in[1][stt_n1] <= in[2][stt_n2]) return 0;
    return 1;
}*/

int main()
{
    /*in.resize(2);
    cin >> n1;
    in[0].resize(n1+1);
    For(i, 0, n1) cin >> in[0][i];
    cin >> n2;
    in[1].resize(n2+1);
    For(i, 0, n2) cin >> in[1][i];
    int64_t stt_n1 = 0, stt_n2 = 0;
    vector <int64_t> out;
    /*while (stt_n1 < n1 && stt_n2 < n2)
    {
        bool check = switch_n(stt_n1, stt_n2);
        int64_t& rstt = stt_n2;
        if (check == 0) rstt = stt_n1;
        out.push_back(in[check][rstt]);
        rstt++;
        //out.push_back(in[check][(check == 0) ? stt_n1++ : stt_n2++]);
        //out.push_back( in [switch_n(stt_n1, stt_n2)] [ (stt_n1 == switch_n(stt_n1, stt_n2)) ? stt_n1++ : stt_n2++] );
    }
    while (stt_n1 < n1)
    {
        out.push_back(in[0][stt_n1]);
        stt_n1++;
    }
    while (stt_n2 < n2)
    {
        out.push_back(in[1][stt_n2]);
        stt_n2++;
    }*/
    cin >> n1;
    int64_t A[n1+5];
    For(i, 0, n1) cin >> A[i];
    cin >> n2;
    int64_t B[n2+5];
    For(i, 0, n2) cin >> B[i];
    int C[n1 + n2];
    merge(A, (A + n1), B, (B + n2), C);
    For(i, 0, n1+n2)
    cout << C[i] << ' ';
    return 0;
}
