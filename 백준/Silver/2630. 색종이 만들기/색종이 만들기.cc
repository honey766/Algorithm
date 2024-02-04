#include <iostream>
using namespace std;

int white, blue;
bool** arr;

void f(int, int, int);
void check(int n, int x, int y) {
    bool iswhite = true, isblue = true;
    for (int i = y; i < y + n; ++i) {
        for (int j = x; j < x + n; ++j) {
            if (arr[i][j]) iswhite = false;
            else isblue = false;
        }
        if (!iswhite && !isblue) break;
    }
    if (iswhite) ++white;
    else if (isblue) ++blue;
    else f(n, x, y);
}

void f(int n, int x, int y) {
    if (n == 1) return;
    int sn = n / 2;
    check(sn, x, y);
    check(sn, x + sn, y);
    check(sn, x, y + sn);
    check(sn, x + sn, y + sn);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int a, n; cin >> n;
    arr = new bool* [n];
    for (int i = 0; i < n; ++i)
        arr[i] = new bool[n];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> arr[i][j];
    white = blue = 0;
    check(n, 0, 0);
    cout << white << '\n' << blue;
}