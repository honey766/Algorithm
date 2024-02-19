#include <iostream>
using namespace std;

short arr[30];
bool dp[40001][30]; // dp[i][j] : 숫자 i를 0~j번째 추로 측정할 수 있음

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int n1, n2, a;
	cin >> n1;
	for (int i = 0; i < n1; i++) {
		cin >> arr[i];
	}
	dp[arr[0]][0] = true;
	for (int j = 1; j < n1; j++) {
		dp[0][j - 1] = true;
		for (int i = 1; i <= 40000; i++) {
			a = (i > arr[j] ? i - arr[j] : arr[j] - i);
			dp[i][j] = dp[i][j - 1] || dp[a][j - 1];
			if (i + arr[j] <= 40000)
				dp[i][j] = dp[i][j] || dp[i + arr[j]][j - 1];
		}
	}

	cin >> n2;
	for (int i = 0; i < n2; i++) {
		cin >> a;
		if (dp[a][n1 - 1]) cout << "Y ";
		else cout << "N ";
	}
}