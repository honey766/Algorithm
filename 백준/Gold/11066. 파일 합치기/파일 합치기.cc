#include <iostream>
using namespace std;

int file[501], dp[500][500]; //i~j까지 파일 합칠 때 최솟값

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int t, k, i, j;
	cin >> t;
	file[0] = 0;
	while (t--) {
		cin >> k;
		for (i = 0; i < k; i++) {
			cin >> file[i + 1];
			file[i + 1] += file[i];
		}
		for (i = 0; i < k - 1; i++)
			dp[i][i + 1] = file[i + 2] - file[i];

		for (int len = 2; len < k; len++)
			for (i = 0; i < k - len; i++) {
				dp[i][i + len] = min(dp[i][i + len - 1], dp[i + 1][i + len]);
				for (j = i + 1; j < i + len - 1; j++) {
					dp[i][i + len] = min(dp[i][i + len], dp[i][j] + dp[j + 1][i + len]);
				}
				dp[i][i + len] += file[i + len + 1] - file[i];
			}

		cout << dp[0][k - 1] << '\n';
	}
}