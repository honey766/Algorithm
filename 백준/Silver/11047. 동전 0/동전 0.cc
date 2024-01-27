#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, k, cnt = 0;
    cin >> n >> k;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = n - 1; i >= 0; i--) {
        cnt += k / arr[i];
        k %= arr[i];
    }
    cout << cnt;
}