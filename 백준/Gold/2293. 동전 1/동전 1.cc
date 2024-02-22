#include <iostream>
using namespace std;

int dp[10001];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, k, a;
	cin >> n >> k;
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		cin >> a;
		//해당 동전을 쓰는 경우를, i-1번째까지 동전만 쓰는 경우의 수에 더해간다.
		//해당 동전(a원짜리)을 1개 이상 써서 j원을 만드는 경우의 수는 dp[j - a]이다.
		for (int j = 1; j <= k; j++)
			if (j - a >= 0)
				dp[j] += dp[j - a];
	}
	cout << dp[k];
}