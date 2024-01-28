#include <iostream>
using namespace std;

int arr[1025][1025];
int rowSum[1025][1025];
int colSum[1025][1025];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m, x1, y1, x2, y2, sum;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];
    for (int i = 1; i <= n; i++) {
        rowSum[i][0] = 0;
        colSum[0][i] = 0;
        for (int j = 1; j <= n; j++) {
            rowSum[i][j] = rowSum[i][j - 1] + arr[i][j]; //ith 행에서 j번째까지 더함
            colSum[j][i] = colSum[j - 1][i] + arr[j][i]; //ith 열에서 j번째까지 더함
        }
    }
    while (m--) {
        sum = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x2 - x1 < y2 - y1)
            for (int i = x1; i <= x2; i++)
                sum += rowSum[i][y2] - rowSum[i][y1 - 1];
        else
            for (int i = y1; i <= y2; i++)
                sum += colSum[x2][i] - colSum[x1 - 1][i];
        cout << sum << '\n';
    }
}