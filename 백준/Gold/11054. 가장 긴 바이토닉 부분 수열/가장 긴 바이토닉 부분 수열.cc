#include <iostream>
using namespace std;

void cal(int* arr, int* dp, int n, bool incr) {
    int Max = 0;
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (incr && arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
            else if (!incr && arr[n - 1 - j] < arr[n - 1 - i])
                dp[n - 1 - i] = max(dp[n - 1 - i], dp[n - 1 - j] + 1);
        }
        Max = max(Max, dp[i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, Max = -1;
    cin >> n;
    int* arr = new int[n];
    int* dpIncr = new int[n]();
    int* dpDecr = new int[n]();
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cal(arr, dpIncr, n, true);
    cal(arr, dpDecr, n, false);
    for (int i = 0; i < n; i++)
        Max = max(Max, dpIncr[i] + dpDecr[i] + 1);
    cout << Max;
}