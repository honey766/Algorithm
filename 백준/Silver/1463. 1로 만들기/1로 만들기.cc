#include <iostream>
using namespace std;
#define MIN(x,y) ((x) > (y) ? (y) : (x))

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n;
	cin >> n;
	int* dp = new int[n + 1];
	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		dp[i] = 10000000;
		if (i % 2 == 0)
			dp[i] = MIN(dp[i / 2], dp[i]);
		if (i % 3 == 0)
			dp[i] = MIN(dp[i / 3], dp[i]);
		dp[i] = MIN(dp[i - 1], dp[i]) + 1;
	}
	cout << dp[n];
}