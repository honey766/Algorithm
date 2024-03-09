#include <iostream>
using namespace std;

int main() {
	int n, m, M, t, r;
	cin >> n >> m >> M >> t >> r;
	int cnt = 0, x = m;
	if (m + t > M) {
		cout << "-1";
		return 0;
	}
	while (n) {
		cnt++;
		if (x + t <= M) {
			x += t;
			n--;
		}
		else {
			x -= r;
			if (x < m) x = m;
		}
	}
	cout << cnt;
}