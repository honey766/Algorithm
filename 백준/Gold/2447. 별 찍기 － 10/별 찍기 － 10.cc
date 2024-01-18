#include <iostream>
using namespace std;

void f2(int n, int i) {
    if (n == 1) {
        cout << '*'; return;
    }
    int sn = n / 3;
    if (i < sn) { 
        for (int j = 0; j < 3; j++)
            f2(sn, i);
    }
    else if (i < 2 * sn) {
        f2(sn, i % sn);
        for (int j = 0; j < sn; j++) cout << ' ';
        f2(sn, i % sn);
    }
    else {
        for (int j = 0; j < 3; j++)
            f2(sn, i % sn);
    }
}

void f(int n) {
    for (int i = 0; i < n; i++) {
        f2(n, i); cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    f(n);
}