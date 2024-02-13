#include <iostream>
using namespace std;
#define MAX(x, y) ((x) > (y) ? (x) : (y))

short n, m;
short arr[500][500];

short f1(int i, int j) { //정사각형
    if (i == n - 1 || j == m - 1) return 0;
    return arr[i][j] + arr[i + 1][j] + arr[i][j + 1] + arr[i + 1][j + 1];
}

short f2(int i, int j) { //L 모양
    int Max = 0;
    if (i < n - 2 && j < m - 1)
        Max = MAX(Max, arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + MAX(arr[i + 2][j + 1], arr[i][j + 1]));
    if (i < n - 2 && 0 < j)
        Max = MAX(Max, arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + MAX(arr[i + 2][j - 1], arr[i][j - 1]));
    if (i < n - 1 && j < m - 2)
        Max = MAX(Max, arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + MAX(arr[i + 1][j + 2], arr[i + 1][j]));
    if (0 < i && j < m - 2)
        Max = MAX(Max, arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + MAX(arr[i - 1][j + 2], arr[i - 1][j]));
    return Max;
}

short f3(int i, int j) {//번개 모양
    int Max = 0;
    if (i < n - 2 && j < m - 1)
        Max = MAX(Max, arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j + 1]);
    if (i < n - 2 && 0 < j)
        Max = MAX(Max, arr[i][j] + arr[i + 1][j] + arr[i + 1][j - 1] + arr[i + 2][j - 1]);
    if (i < n - 1 && j < m - 2)
        Max = MAX(Max, arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j + 2]);
    if(0 < i && j < m - 2)
        Max = MAX(Max, arr[i][j] + arr[i][j + 1] + arr[i - 1][j + 1] + arr[i - 1][j + 2]);
    return Max;
}

short f4(int i, int j) {//ㅜ 모양
    int Max = 0;
    if (i < n - 1 && j < m - 2)
        Max = MAX(Max, arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i][j + 2]);
    if (0 < i && j < m - 2)
        Max = MAX(Max, arr[i][j] + arr[i][j + 1] + arr[i - 1][j + 1] + arr[i][j + 2]);
    if (i < n - 2 && j < m - 1)
        Max = MAX(Max, arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j]);
    if (i < n - 2 && 0 < j)
        Max = MAX(Max, arr[i][j] + arr[i + 1][j] + arr[i + 1][j - 1] + arr[i + 2][j]);
    return Max;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int Max = -1, tmp;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> arr[i][j];

    for (int i = 0; i < n; ++i) {
        tmp = arr[i][0] + arr[i][1] + arr[i][2] + arr[i][3];
        Max = MAX(Max, tmp);
        for (int j = 1; j < m - 3; ++j) {
            tmp += arr[i][j + 3] - arr[i][j - 1];
            Max = MAX(Max, tmp);
        }
    }
    for (int i = 0; i < m; ++i) {
        tmp = arr[0][i] + arr[1][i] + arr[2][i] + arr[3][i];
        Max = MAX(Max, tmp);
        for (int j = 4; j < n; ++j) {
            tmp += arr[j][i] - arr[j - 4][i];
            Max = MAX(Max, tmp);
        }
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) 
            Max = MAX(MAX(MAX(MAX(Max, f1(i, j)), f2(i, j)), f3(i, j)), f4(i, j));
    cout << Max;
}