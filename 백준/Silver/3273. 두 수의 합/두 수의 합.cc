#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, x;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> x;
    sort(arr, arr + n);

    int start, end, result;
    start = result = 0;
    end = n - 1;
    while (start < end) {
        if (arr[start] + arr[end] >= x) {
            if (arr[start] + arr[end] == x)
                result++;
            end--;
        }
        else
            start++;
    }
    cout << result;
}