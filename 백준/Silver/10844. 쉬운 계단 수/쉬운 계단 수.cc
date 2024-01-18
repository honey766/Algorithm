#include <iostream>
using namespace std;
#define MIN(x,y) ((x) > (y) ? (y) : (x))

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, sum = 0, L = 1000000000;
	cin >> n;
	int dp[101][10]; //dp[i][j] : 길이가 i인 계단 수 중에, 숫자 j로 시작하는 개수
	for (int i = 1; i < 10; i++)
		dp[1][i] = 1;
	dp[0][1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i][1] = (dp[i - 2][1] + dp[i - 1][2]) % L; //101...  12...
		for (int j = 2; j <= 8; j++)
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % L;
		dp[i][9] = dp[i - 1][8];
	}
	for (int i = 1; i < 10; i++)
		sum = (sum + dp[n][i]) % L;
	cout << sum;
}