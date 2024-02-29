#include <iostream>
using namespace std;
#define ll long long
#define N 1'000'000'007

int base;
int arr[2'097'152];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, m, k, a, b, c, i;
	base = 1;
	cin >> n >> m >> k;
	while (base < n) base <<= 1;
	for (i = base; i < base + n; i++)
		cin >> arr[i];
	for (; i < 2 * base; i++)
		arr[i] = 1;
	for (i = base - 1; i >= 0; i--)
		arr[i] = ((ll)arr[2 * i] * arr[2 * i + 1]) % N;

	m += k;
	while (m--) {
		cin >> a >> b >> c;
		b += base - 1;
		if (a == 1) { //b번째 수를 c로 바꿈
			arr[b] = c;
			while (b /= 2)
				arr[b] = ((ll)arr[2 * b] * arr[2 * b + 1]) % N;
		}
		else { //b~c번째 수의 합
			c--;
			int sum = 1;
			for (c += base; b <= c; b >>= 1, c >>= 1) {
				if (b % 2 == 1) sum = ((ll)sum * arr[b++]) % N;
				if (c % 2 == 0) sum = ((ll)sum * arr[c--]) % N;
			}
			cout << sum << '\n';
		}
	}
}