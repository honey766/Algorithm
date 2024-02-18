#include <iostream>
using namespace std;

int evenB[2001][2001]; //(1, 1) ~ (i, j) 칸에 B가 몇 개 (i+j는 짝수)
int oddW[2001][2001]; //(1, 1) ~ (i, j) 칸에 W가 몇 개 (i+j는 홀수)

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, m, k, b, w, cnt, Min = 10'000'000;
	char c;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> c;
			if ((i + j) % 2 == 0 && c == 'B')
				evenB[i][j] = 1;
			else if ((i + j) % 2 && c == 'W')
				oddW[i][j] = 1;
			evenB[i][j] += evenB[i - 1][j] + evenB[i][j - 1] - evenB[i - 1][j - 1];
			oddW[i][j] += oddW[i - 1][j] + oddW[i][j - 1] - oddW[i - 1][j - 1];
		}
	}
	for (int i = 0; i <= n - k; i++) {
		for (int j = 0; j <= m - k; j++) {
			b = evenB[i + k][j + k] - evenB[i][j + k] - evenB[i + k][j] + evenB[i][j];
			w = oddW[i + k][j + k] - oddW[i][j + k] - oddW[i + k][j] + oddW[i][j];
			cnt = k * k - b - w; //잘못된 개수
			cnt = (cnt > k * k / 2) ? k * k - cnt : cnt;
			Min = min(Min, cnt);
		}
	}
	cout << Min;
}