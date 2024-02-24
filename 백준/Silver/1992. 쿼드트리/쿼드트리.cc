#include <iostream>
using namespace std;

short arr[65][65];

// 시작점 (i, j), n*n칸
void print(int i, int j, int n) {
	int cnt = arr[i + n][j + n] - arr[i][j + n] - arr[i + n][j] + arr[i][j];
	if (cnt == n * n) cout << 1;
	else if (cnt == 0) cout << 0;
	else {
		int sn = n / 2;
		cout << '(';
		print(i, j, sn);
		print(i, j + sn, sn);
		print(i + sn, j, sn);
		print(i + sn, j + sn, sn);
		cout << ')';
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n;
	string s;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		for (int j = 1; j <= n; j++)
			arr[i][j] = (s[j - 1] - '0') + arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
	}
	print(0, 0, n);
}