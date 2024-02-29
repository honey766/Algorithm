#include <iostream>
using namespace std;

int dp[22][1<<4]; //dp[i][status] : 4*(i-1)까지는 다 채우고, i열에서는 status에 해당하는 곳만 채움
				  //dp[4][1001(2)] : 3열까지는 다 채우고, 4열의 1행, 4행만 채우는 경우의 수
				  //4*21까지는 int 범위 내에 들어감

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	dp[0][0b1111] = dp[1][0b1100] = dp[1][0b0110] = dp[1][0b0011] = dp[1][0b1111] = 1;
	for(int i = 2; i <= 21; i++){
		dp[i][0b1000] = dp[i - 1][0b0111];
		dp[i][0b0100] = dp[i - 1][0b1011];
		dp[i][0b0010] = dp[i - 1][0b1101];
		dp[i][0b0001] = dp[i - 1][0b1110];

		dp[i][0b1100] = dp[i - 1][0b1111] + dp[i - 1][0b0011];
		dp[i][0b0110] = dp[i - 1][0b1111] + dp[i - 1][0b1001];
		dp[i][0b0011] = dp[i - 1][0b1111] + dp[i - 1][0b1100];
		dp[i][0b1010] = dp[i - 1][0b0101];
		dp[i][0b0101] = dp[i - 1][0b1010];
		dp[i][0b1001] = dp[i - 1][0b0110];

		dp[i][0b1110] = dp[i - 1][0b1101] + dp[i - 1][0b0111] + dp[i - 1][0b0001];
		dp[i][0b0111] = dp[i - 1][0b1110] + dp[i - 1][0b1011] + dp[i - 1][0b1000];
		dp[i][0b1011] = dp[i - 1][0b0111] + dp[i - 1][0b0100];
		dp[i][0b1101] = dp[i - 1][0b1110] + dp[i - 1][0b0010];

		dp[i][0b1111] = dp[i - 1][0b1111] + dp[i - 1][0b0011] + dp[i - 1][0b1100] + dp[i - 1][0b0110] + dp[i - 2][0b1111];
	}

	int t, a;
	cin >> t;
	while (t--) {
		cin >> a;
		cout << dp[a][15] << '\n';
	}
}