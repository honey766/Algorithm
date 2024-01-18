#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int r, c, max = 0, mins, temp;
    string s;
    cin >> r >> c;
    char** arr = new char* [r];
    int** left = new int* [r]; //대각선 위,왼쪽 1이 연속 몇 개
    int** right = new int* [r]; // 대각선 위,오른쪽 1이 연속 몇 개
    for (int i = 0; i < r; i++) {
        arr[i] = new char[c];
        left[i] = new int[c]();
        right[i] = new int[c]();
    }
    for (int i = 0; i < r; i++) {
        cin >> s;
        for (int j = 0; j < c; j++)
            arr[i][j] = s[j] - '0';
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (j < c - 1 && i > 0) {
                if (arr[i][j]) right[i][j] = right[i - 1][j + 1] + 1;
                else right[i][j] = 0;
            }
            else right[i][j] = arr[i][j];

            if (j > 0 && i > 0) {
                if (arr[i][j]) left[i][j] = left[i - 1][j - 1] + 1;
                else left[i][j] = 0;
            }
            else left[i][j] = arr[i][j];
        }
    }
    for (int i = r - 1; i >= 0; i--) {
        for (int j = c - 1; j >= 0; j--) {
            if (left[i][j] <= max || right[i][j] <= max) continue;
            mins = min(left[i][j], right[i][j]);
            temp = max - 1;
            while(++temp < mins)
                if (i - temp >= 0 && j - temp >= 0 && j + temp < c &&
                    right[i - temp][j - temp] > temp && left[i - temp][j + temp] > temp) {
                    max = temp + 1;
                }
        }
    }
    cout << max;
}