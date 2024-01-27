#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, Max;
    cin >> n;
    int* arr = new int[n];
    int* dp = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i] = arr[i];
    }
    Max = dp[0];
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--)
            if (arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + arr[i]);
        Max = max(Max, dp[i]);
    }
    cout << Max;
}