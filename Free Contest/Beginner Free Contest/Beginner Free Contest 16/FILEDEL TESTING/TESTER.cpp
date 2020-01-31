#include <bits/stdc++.h>
using namespace std;
int64_t n, q;
string st, output_file;
 
int main()
{
    ofstream outt("result.ans");
    for(int iTest = 0; iTest < 10; iTest++)
    {
        ifstream inp_test("input.00" + (char) (iTest + '0'));
        ofstream inp_program("test.in");
        inp_test >> n >> q;
        inp_program << n << ' ' << q << "\n";
        for(int64_t i = 1; i <= n; i++)
        {
            inp_test >> st;
            inp_program << st;
        }
        for(int64_t i = 1; i <= n; i++)
        {
            inp_test >> st;
            inp_program << st;
        }
        inp_test.close();
        inp_program.close();
        system("FILEDEL");
        output_file = "output.00" + (char) (iTest + '0');
        if(system("fc output_file test.ok") != 0)
        outt << "Test " << iTest << ": WRONG!\n";
        else
        outt << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}