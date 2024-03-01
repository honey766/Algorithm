#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, cnt = 0; //cnt : 현재 처리한 삼각형 개수
	char** arr;
	string s;
	cin >> n;
	arr = new char* [n];
	for (int i = 0; i < n; i++)
		arr[i] = new char[i + 1];
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < i + 1; j++)
			arr[i][j] = s[j];
	}

	//빨간 삼각형은 위에서부터 처리
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (arr[i][j] == 'R' && arr[i+1][j] == 'R' && arr[i+1][j+1] == 'R') {
				cnt += 3;
				arr[i][j] = arr[i + 1][j] = arr[i + 1][j + 1] = 0;
			}
		}
	}
	//파란 삼각형은 아래부터 처리
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i + 1; j++) {
			if (j < i && arr[i][j] == 'B' && arr[i - 1][j] == 'B' && arr[i - 1][j - 1] == 'B') {
				cnt += 3;
				arr[i][j] = arr[i - 1][j] = arr[i - 1][j - 1] = 0;
			}
		}
	}

	if (cnt == n * (n + 1) / 2) cout << 1;
	else cout << 0;
}