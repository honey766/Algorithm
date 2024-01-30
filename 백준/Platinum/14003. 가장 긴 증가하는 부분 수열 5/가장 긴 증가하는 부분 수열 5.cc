#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, last = 0, size = 1;
    cin >> n;
    int* arr = new int[n];
    int* incr = new int[n];
    int* dp = new int[n]; //자기 자신 포함, 0~i까지 최대 길이
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    incr[0] = arr[0]; dp[0] = 1;
    for (int i = 1; i < n; ++i) {
        if (arr[i] > incr[size - 1]) {
            incr[size++] = arr[i];
            dp[i] = size;
            last = i;
        }
        else {
            int idx = lower_bound(incr, incr + size, arr[i]) - incr;
            dp[i] = idx + 1;
            incr[idx] = arr[i];
        }
    }
    int* ans = new int[size];
    for (int i = last, j = size; i >= 0 && j > 0; --i)
        if (dp[i] == j)
            ans[--j] = arr[i];
    cout << size << '\n';
    for (int i = 0; i < size; i++)
        cout << ans[i] << ' ';
}