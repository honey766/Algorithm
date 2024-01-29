#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

bool f(bool arr[50][50], int m, int n, int i, int j) {
    if (!arr[i][j]) return false;
    arr[i][j] = 0;
    if (i > 0) f(arr, m, n, i - 1, j);
    if (i < m - 1) f(arr, m, n, i + 1, j);
    if (j > 0) f(arr, m, n, i, j - 1);
    if (j < n - 1) f(arr, m, n, i, j + 1);
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t, m, n, k, x, y, cnt;
    bool arr[50][50];
    cin >> t;
    while (t--) {
        cnt = 0;
        memset(arr, 0, 2500);
        cin >> m >> n >> k;
        while (k--) {
            cin >> x >> y;
            arr[x][y] = 1;
        }
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (f(arr, m, n, i, j)) 
                    ++cnt;
        cout << cnt << '\n';
    }
}