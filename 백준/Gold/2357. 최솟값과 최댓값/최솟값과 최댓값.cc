#include <iostream>
using namespace std;
#define INF 2'000'000'000

int n, base;
int Max[262'144];
int Min[262'144];

void init() {
	int a, i;
	for (i = base; i < base + n; i++) {
		cin >> Max[i];
		Min[i] = Max[i];
	}
	for (; i < 2 * base; i++)
		Min[i] = INF;
	for (i = base - 1; i > 0; i--) {
		Max[i] = max(Max[2 * i], Max[2 * i + 1]);
		Min[i] = min(Min[2 * i], Min[2 * i + 1]);
	}
}

void query(int l, int r) {
	int maxV = 0, minV = INF;
	for (l += base, r += base; l <= r; l >>= 1, r >>= 1) {
		if (l % 2 == 1) {
			maxV = max(maxV, Max[l]);
			minV = min(minV, Min[l++]);
		}
		if (r % 2 == 0) {
			maxV = max(maxV, Max[r]);
			minV = min(minV, Min[r--]);
		}
	}
	cout << minV << ' ' << maxV << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int m, a, b;
	cin >> n >> m;
	base = 1;
	while (base < n) base <<= 1;
	init();
	while (m--) {
		cin >> a >> b;
		query(--a, --b);
	}
}