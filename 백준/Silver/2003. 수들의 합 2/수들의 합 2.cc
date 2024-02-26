#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    int* arr = new int[n];
    int start, end, result, sum;
    start = end = result = sum = 0;
    while (start < n) {
        if (sum >= m || end >= n) {
            if (sum == m)
                result++;
            sum -= arr[start++];
        }
        else if (sum < m) {
            cin >> arr[end];
            sum += arr[end++];
        }
    }
    cout << result;
}