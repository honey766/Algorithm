#include <iostream>
using namespace std;
#define ll long long

int base;
ll arr[2'097'152];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, m, k, a, b, i;
	ll c;
	base = 1;
	cin >> n >> m >> k;
	while (base < n) base <<= 1;
	for (i = 0; i < n; i++)
		cin >> arr[base + i];
	for (i = base - 1; i >= 0; i--)
		arr[i] = arr[2 * i] + arr[2 * i + 1];

	m += k;
	while (m--) {
		cin >> a >> b >> c;
		b += base - 1;
		if (a == 1) { //b번째 수를 c로 바꿈
			arr[b] = c;
			while (b /= 2)
				arr[b] = arr[2 * b] + arr[2 * b + 1];
		}
		else { //b~c번째 수의 합
			c--;
			ll sum = 0;
			for (c += base; b <= c; b >>= 1, c >>= 1) {
				if (b % 2 == 1) sum += arr[b++];
				if (c % 2 == 0) sum += arr[c--];
			}
			cout << sum << '\n';
		}
	}
}