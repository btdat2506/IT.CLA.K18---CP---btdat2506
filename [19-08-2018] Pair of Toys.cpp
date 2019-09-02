#include <iostream>

using namespace std;

void result(long long n)
{
    cout << n << endl; exit(EXIT_SUCCESS);
}

int main()
{
    long long n, k;
    cin >> n >> k;
	if ((k - n) >= n) result(0);
	else if (n >= k)
	{
		if (k % 2 == 0) result((k-2)/2);
		else result((k-1)/2);
	}
    else result((n - (k - n) + 1) / 2);
    return 0;
}