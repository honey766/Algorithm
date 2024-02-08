#include <iostream>
using namespace std;

short dp[1001][1001]; //dp[i][j] : 각 문자열의 i-1, j-1번째까지 봤을 때 LCS

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	string s1, s2;
	cin >> s1 >> s2;
	int n = s1.size();
	int m = s2.size();

	for (int i = 0; i < n; ++i) 
		dp[i][0] = 0;
	for (int i = 0; i < m; ++i)
		dp[0][i] = 0;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	cout << dp[n][m];
}