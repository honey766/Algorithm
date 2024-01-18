#include <iostream>
using namespace std;
#define MAX(x,y) ((x) > (y) ? (x) : (y))

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, Max, **arr, **dp;
	cin >> n;
	arr = new int* [n];
	dp = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[i + 1];
		dp[i] = new int[i + 1];
		for (int j = 0; j <= i; j++)
			cin >> arr[i][j];
	}
	dp[0][0] = arr[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) dp[i][j] = dp[i - 1][j] + arr[i][j];
			else if (j == i) dp[i][j] = dp[i - 1][j - 1] + arr[i][j];
			else dp[i][j] = MAX(dp[i - 1][j], dp[i - 1][j - 1]) + arr[i][j];
		}
	}
	Max = -1;
	for (int i = 0; i < n; i++)
		Max = MAX(Max, dp[n - 1][i]);
	cout << Max;
}