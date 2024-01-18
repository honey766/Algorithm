#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    double a = 1;
    cin >> n >> m;
    for (int i = n; i > n - m; i--)
        a = a * i / (n - i + 1);
    cout << (int)a;
}