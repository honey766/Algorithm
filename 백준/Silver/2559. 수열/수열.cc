#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, k, Max = -1000000000;
    cin >> n >> k;
    int* arr = new int[n + 1];
    arr[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    for (int i = k; i <= n; i++) {
        Max = max(Max, arr[i] - arr[i - k]);
    }
    cout << Max;
}