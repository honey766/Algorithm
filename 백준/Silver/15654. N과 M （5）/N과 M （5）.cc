#include <iostream>
#include <algorithm>
using namespace std;

int n, m, arr[8], ans[8];
void f(int i, int status) {
	if (i == m) {
		for (int j = 0; j < m; j++)
			cout << ans[j] << ' ';
		cout << '\n';
		return;
	}
	for (int j = 0; j < n; j++) {
		if (status & (1 << j)) continue;
		ans[i] = arr[j];
		f(i + 1, status | (1 << j));
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	f(0, 0);
}