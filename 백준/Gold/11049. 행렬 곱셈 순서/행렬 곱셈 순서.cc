#include <iostream>
using namespace std;
#define INF 2'000'000'000

int arr[500][2], dp[500][500]; //i~j번째 행렬 합칠 때 최솟값

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i][0] >> arr[i][1];

	for (int len = 1; len < n; len++)
		for (int i = 0; i < n - len; i++) {
			dp[i][i + len] = INF;
			for (int j = i; j < i + len; j++)//i~j행렬과 j+1~i+len 행렬 합침
				dp[i][i + len] = min(dp[i][i + len], dp[i][j] + dp[j + 1][i + len] + arr[i][0] * arr[j][1] * arr[i + len][1]);
		}
	cout << dp[0][n - 1];
}