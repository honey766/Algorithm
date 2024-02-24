#include <iostream>
using namespace std;
#define N 1'000'000'007

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, k, i;
	long long a1, a2, ret, aa[2] = { 1, 1 };
	cin >> n >> k;
	a1 = ret = 1;
	for (i = 2; i <= n; i++) {
		a1 = (a1 * i) % N;
		if (i == k) aa[0] = a1;
		if (i == n - k) aa[1] = a1;
	}
	a2 = (aa[0] * aa[1]) % N;
	//구하려는 것은 (a1 / a2) % N
	// == (a1 * (a2 ^ (N-2))) % N

	n = N - 2;
	while (n) {
		if (n % 2)
			ret = (ret * a2) % N;
		a2 = (a2 * a2) % N;
		n /= 2;
	}
	cout << (a1 * ret) % N;
}