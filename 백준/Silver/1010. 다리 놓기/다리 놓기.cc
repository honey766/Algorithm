#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t, n, m;
    double a;
    cin >> t;
    for (int i = 0; i < t; i++) {
        a = 1;
        cin >> m >> n;
        for (int j = n; j > n - m; j--)
            a = a * j / (n - j + 1);
        cout << (int)a << '\n';
    }
}