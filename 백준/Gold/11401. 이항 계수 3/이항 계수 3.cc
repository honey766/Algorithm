#include <iostream>
using namespace std;
#define N 1'000'000'007

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, k, i;
	long long a1, a2, a3, ret;
	cin >> n >> k;
	a1 = a2 = a3 = ret = 1;
	for (i = 2; i <= n; i++)
		a1 = (a1 * i) % N;
	for (i = 2; i <= k; i++)
		a2 = (a2 * i) % N;
	for (i = 2; i <= n - k; i++)
		a3 = (a3 * i) % N;
	a2 = (a2 * a3) % N;
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