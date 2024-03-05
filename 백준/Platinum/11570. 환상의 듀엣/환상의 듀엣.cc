#include <iostream>
using namespace std;
#define INF 2'100'000'000
//https://huiung.tistory.com/119

int a[2001];
int dp[2001][2001];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, Max, Min;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			dp[i][j] = INF;
	dp[1][0] = dp[0][1] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			Max = max(i, j) + 1;
			if (i == 0 || j == 0) a[0] = a[Max];
			dp[Max][j] = min(dp[Max][j], dp[i][j] + abs(a[Max] - a[i]));
			dp[i][Max] = min(dp[i][Max], dp[i][j] + abs(a[Max] - a[j]));
		}
	}
	Min = dp[n][0];
	for (int i = 1; i < n; i++)
		Min = min(Min, dp[n][i]);
	cout << Min;
}