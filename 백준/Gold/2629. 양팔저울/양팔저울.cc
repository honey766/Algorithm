#include <iostream>
using namespace std;
#define f(j) ((j) % 2)

short arr[30];
bool dp[40001][2]; // dp[i][j % 2] : 숫자 i를 0~j번째 추로 측정할 수 있음

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n1, n2, a;
	cin >> n1;
	for (int i = 0; i < n1; i++) {
		cin >> arr[i];
	}
	dp[0][0] = dp[0][1] = dp[arr[0]][0] = true;
	for (int j = 1; j < n1; j++) {
		for (int i = 1; i <= 40000; i++) {
			a = (i > arr[j] ? i - arr[j] : arr[j] - i);
			dp[i][f(j)] = dp[i][f(j - 1)] || dp[a][f(j - 1)];
			if (i + arr[j] <= 40000)
				dp[i][f(j)] = dp[i][f(j)] || dp[i + arr[j]][f(j - 1)];
		}
	}

	cin >> n2;
	for (int i = 0; i < n2; i++) {
		cin >> a;
		if (dp[a][f(n1 - 1)]) cout << "Y ";
		else cout << "N ";
	}
}