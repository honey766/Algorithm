#include <iostream>
using namespace std;

int n, m;
int arr[8];

void print(int cnt) {
	if (cnt == m) {
		for (int j = 0; j < m; j++)
			cout << arr[j] << ' ';
		cout << '\n'; return;
	}
	int i = (cnt == 0 ? 0 : arr[cnt - 1] - 1);
	for (; i < n; i++) {
		arr[cnt] = i + 1;
		print(cnt + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> n >> m;
	print(0);
}