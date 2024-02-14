#include <iostream>
#include <algorithm>
using namespace std;

//x보다 작거나 같은 원소 중 최대인 idx 반환
int bound(int* arr, int n, int x) {
    int l = 0, r = n - 1, mid;
    while (l < r) {
        mid = (l + r + 1) / 2;
        if (arr[mid] < x)
            l = mid;
        else if (arr[mid] > x)
            r = mid - 1;
        else return mid;
    }
    return r;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, s, Min = 200000;
    cin >> n >> s;
    int* arr = new int[n + 1];
    arr[0] = 0;
    cin >> arr[1];
    for (int i = 2; i <= n; ++i) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    if (arr[n] < s) {
        cout << 0;
        return 0;
    }

    int ridx = lower_bound(arr, arr + n + 1, s) - arr;
    for (int i = ridx; i <= n; ++i) {
        int lidx = bound(arr, n + 1, arr[i] - s);
        Min = min(Min, i - lidx);
    }
    cout << Min;
}