#include <iostream>
using namespace std;
#define MAX(x, y) ((x) > (y) ? (x) : (y))

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, Max; cin >> n;
	int* arr = new int[n];
	int* dp = new int[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	Max = dp[0] = 1;
	for (int i = 1; i < n; i++) {
		dp[i] = 0;
		for (int j = i - 1; j >= 0; j--)
			if (arr[j] < arr[i])
				dp[i] = MAX(dp[i], dp[j]);
		dp[i]++;
		Max = MAX(Max, dp[i]);
	}
	cout << Max;
}