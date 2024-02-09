#include <iostream>
using namespace std;

int n, m;
int* arr;

bool f(int mid) {
    long long cut = 0;
    for (int i = 0; i < n && cut < m; ++i)
        cut += arr[i] > mid ? arr[i] - mid : 0;
    return cut >= m;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    int Max = -1;
    arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        Max = Max > arr[i] ? Max : arr[i];
    }

    int l = 0, r = Max, mid;
    while (l < r) {
        mid = (l + r + 1) / 2;
        if (f(mid)) l = mid;
        else r = mid - 1;
    }
    cout << r;
}