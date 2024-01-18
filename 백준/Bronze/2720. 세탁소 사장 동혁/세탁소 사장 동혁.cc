#include <iostream>
#include <vector>
using namespace std;

char Invert(int n) {
    if (n < 10) return '0' + n;
    else return 'A' + n - 10;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c;
        cout << c / 25 << ' ';
        c %= 25;
        cout << c / 10 << ' ';
        c %= 10;
        cout << c / 5 << ' ';
        c %= 5;
        cout << c << '\n';
    }
}