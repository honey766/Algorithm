#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m, a; 
    cin >> n >> m;
    int* arr = new int[n + 1];
    arr[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    while (m--) {
        cin >> a >> n;
        cout << arr[n] - arr[a - 1] << '\n';
    }
}