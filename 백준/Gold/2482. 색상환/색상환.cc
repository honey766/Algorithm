#include <iostream>
using namespace std;
#define N 1'000'000'003

int** dp; //dp[i][j] : i ~ n-1에서 j+1개를 고르는 경우의 수

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, k;
	cin >> n >> k;
	dp = new int* [n];
	for (int i = 0; i < n; i++)
		dp[i] = new int[k];
	
	dp[n - 1][0] = 1;
	dp[n - 2][0] = 2;
	for (int j = 1; j < k; j++)
		dp[n - 1][j] = dp[n - 2][j] = 0;
	for (int i = n - 3; i >= 0; i--)
		for (int j = 0; j < k; j++) {
			if (j == 0) dp[i][j] = dp[i + 1][j] + 1;
			else dp[i][j] = dp[i + 1][j] + dp[i + 2][j - 1];
			dp[i][j] %= N;
		}

	//0번째를 안 고름 + 0번째를 고르고, 2번째 이상에서 k-1개를 고름(마지막은 포함X)
	//마지막 색은 안 고르므로, 3번째 이상에서 k-1개를 고르는 것과 같음
	if (k == 1) cout << n;
	else cout << (dp[1][k - 1] + dp[3][k - 2]) % N;
}