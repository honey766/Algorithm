#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int a, b, n; cin >> n;
    pair<int, int>* arr = new pair<int, int>[n];
    int* dp = new int[n]();
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        arr[i] = { a, b };
    }
    sort(arr, arr + n);

    int Max = -1;
    for (int i = 1; i < n; ++i) {
        for (int j = i - 1; j >= 0; --j)
            if (arr[j].second < arr[i].second)
                dp[i] = max(dp[i], dp[j] + 1);
        Max = max(Max, dp[i]);
    }
    cout << n - Max - 1;
}