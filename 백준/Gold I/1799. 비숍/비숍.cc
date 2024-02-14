#include <iostream>
using namespace std;

int n;
char visited[10][10];

void visit(int i, int j, bool isVisiting) {
    int t = (isVisiting ? 1 : -1);
    int min1 = min(i, j), max1 = max(i, j);
    int min2 = min(i, n - j - 1), max2 = max(i, n - j - 1);
    for (int k = -min1; k < n - max1; k++) //왼쪽위~오른아래
        visited[i + k][j + k] += t;
    for (int k = -min2; k < n - max2; k++) //오른쪽위~왼아래
        visited[i + k][j - k] += t;
    visited[i][j] -= t;
}

int bishop(int idx) {
    if (idx >= n * n)
        return 0;
    int cnt = 0;
    //흰칸 혹은 검은칸만 검사
    for (int k = idx; k < n * n; k += 2) {
        int i = k / n;
        int j = k % n;
        if (i % 2 && !(n % 2)) { //보드판 길이가 짝수일 때 처리
            if (k % 2) --j;
            else ++j;
        }
        if (!visited[i][j]) {
            visit(i, j, true);
            cnt = max(cnt, 1 + bishop(k + 2));
            visit(i, j, false);
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int a;
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> a;
            visited[i][j] = 1 - a;
        }
    cout << bishop(0) + bishop(1);
}