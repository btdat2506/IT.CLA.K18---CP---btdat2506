#include <bits/stdc++.h>

using namespace std;

vector <bool> isPrime;

void SangSNT(int l, int r){
for (long long i = 2; i * i <= r; ++i) {
    for (long long j = max(i * i, (l + (i - 1)) / i * i); j <= r; j += i) {
        isPrime[j - l] = false;
    }
}
}

int main()
{
	int l, r;
	cin >> l >> r;
	SangSNT(l, r);
	for (int i = 0; i < r - l + 1; i++) isPrime.push_back(1);
	for (long long i = max(l, 2); i <= r; ++i) {
    if (isPrime[i - l]) cout << i << endl;
	}
	return 0;
}