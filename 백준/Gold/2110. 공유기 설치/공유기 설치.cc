#include <iostream>
#include <algorithm>
using namespace std;

int n, c;
int* arr;
bool f(int mid) {
    int cnt = 0, cur = -1'000'000'000;
    for (int i = 0; i < n; i++)
        if (cur + mid <= arr[i]) {
            cur = arr[i];
            cnt++;
        }
    return (cnt >= c);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int Max = -1;
    cin >> n >> c;
    arr = new int[n];
    for (int i = 0; i < n; i++) 
        cin >> arr[i];
    sort(arr, arr + n);

    int l = 1, r = arr[n - 1], mid;
    while (l < r) {
        mid = (l + r + 1) / 2;
        if (f(mid)) l = mid;
        else r = mid - 1;
    }
    cout << r;
}