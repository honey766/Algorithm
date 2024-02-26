#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);

    int start, end, Min;
    start = end = 0;
    Min = 2'000'000'000;
    while (start < n) {
        if (arr[end] - arr[start] >= m || end >= n) {
            if (arr[end] - arr[start] >= m)
                Min = min(Min, arr[end] - arr[start]);
            start++;
        }
        else
            end++;
    }
    cout << Min;
}