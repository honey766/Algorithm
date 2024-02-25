#include <iostream>
using namespace std;

char arr[100'000][2];
int dp[100'000][2]; //dp[i][j] : i번째 스티커까지, 위(j==0) 또는 아래를 골랐을 때 최댓값

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t, n, a;
	cin >> t;
	while (t--) {
		cin >> n;
		for(int i = 0; i < 2; i++)
			for (int j = 0; j < n; j++) {
				cin >> a;
				arr[j][i] = a;
			}

		dp[0][0] = arr[0][0]; dp[0][1] = arr[0][1];
		dp[1][0] = arr[1][0] + arr[0][1];
		dp[1][1] = arr[1][1] + arr[0][0];
		for (int i = 2; i < n; i++) {
			dp[i][0] = arr[i][0] + max(max(dp[i - 1][1], dp[i - 2][0]), dp[i - 2][1]);
			dp[i][1] = arr[i][1] + max(max(dp[i - 1][0], dp[i - 2][0]), dp[i - 2][1]);
		}
		cout << max(dp[n - 1][0], dp[n - 1][1]) << '\n';
	}
}