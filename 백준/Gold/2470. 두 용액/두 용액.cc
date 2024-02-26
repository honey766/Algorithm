#include <iostream>
#include <algorithm>
using namespace std;
#define ABS(x) ((x) > 0 ? (x) : -(x))

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);

    int s = 0, e = n - 1, ans1, ans2, t, Min = 2'100'000'000;
    while (s < e) {
        t = arr[e] + arr[s];
        if (Min > ABS(t)) {
            Min = ABS(t);
            ans1 = arr[s];
            ans2 = arr[e];
        }
        if (t >= 0) e--;
        else s++;
    }
    cout << ans1 << ' ' << ans2;
}