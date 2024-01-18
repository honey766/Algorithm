#include <iostream>
using namespace std;
#define MAX(x,y) ((x) > (y) ? (x) : (y))

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n;
	cin >> n;
	int* arr = new int[n];
	int* dp = new int[n > 4 ? n : 4];

	for (int i = 0; i < n; i++) cin >> arr[i];
	dp[0] = arr[0];
	dp[1] = arr[0] + arr[1];
	dp[2] = MAX(arr[0], arr[1]) + arr[2];
	dp[3] = MAX(dp[0] + arr[2], dp[1]) + arr[3];
	for (int i = 4; i < n; i++)
		dp[i] = arr[i] + MAX(MAX(dp[i - 4], dp[i - 3]) + arr[i - 1], dp[i - 2]);
	cout << MAX(dp[n - 2], dp[n - 1]);
}