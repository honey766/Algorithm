#include <iostream>
using namespace std;

char dp[1'000'001];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n;
	dp[1] = 0;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0) dp[i] = min(dp[i], char(dp[i / 2] + 1));
		if (i % 3 == 0) dp[i] = min(dp[i], char(dp[i / 3] + 1));
	}
	cout << (int)dp[n] << '\n';


	while (n) {
		cout << n << ' ';
		if (dp[n] == dp[n - 1] + 1) n--;
		else if (n % 2 == 0 && dp[n] == dp[n / 2] + 1) n /= 2;
		else n /= 3;
	}
}