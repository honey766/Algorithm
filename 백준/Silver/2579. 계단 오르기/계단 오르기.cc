#include <iostream>
using namespace std;
#define MAX(x,y) ((x) > (y) ? (x) : (y))

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n;
	cin >> n;
	int* arr = new int[n];
	int* dp = new int[n > 3 ? n : 3];

	for (int i = 0; i < n; i++) cin >> arr[i];
	dp[0] = arr[0];
	dp[1] = arr[0] + arr[1];
	dp[2] = MAX(arr[0], arr[1]) + arr[2];

	for (int i = 3; i < n; i++) {
		dp[i] = MAX(dp[i - 3] + arr[i - 1], dp[i - 2]) + arr[i];
	}
	cout << dp[n - 1];
}