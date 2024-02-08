#include <iostream>
using namespace std;
#define MIN(x,y) ((x) > (y) ? (y) : (x))

int dp[1000][3][3]; //dp[i][j][k] : 1번집 색이 RGB 중 하나(j), i번집 색이 RGB 중 하나(k)
int rgb[1000][3];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, Min = 1000000;
	cin >> n;
	for (int i = 0; i < 3 * n; ++i) cin >> rgb[i / 3][i % 3];

	for (int i = 0; i < 3; ++i) //초기값
		for (int j = 0; j < 3; ++j) {
			if (i == j) dp[1][i][j] = 10000;
			else dp[1][i][j] = rgb[0][i] + rgb[1][j];
		}

	for (int i = 2; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			dp[i][j][0] = MIN(dp[i - 1][j][1], dp[i - 1][j][2]) + rgb[i][0];
			dp[i][j][1] = MIN(dp[i - 1][j][0], dp[i - 1][j][2]) + rgb[i][1];
			dp[i][j][2] = MIN(dp[i - 1][j][0], dp[i - 1][j][1]) + rgb[i][2];
		}
	}

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j) {
			if (i == j) continue;
			Min = MIN(Min, dp[n - 1][i][j]);
		}
	cout << Min;
}