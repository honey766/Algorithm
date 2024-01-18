#include <iostream>
using namespace std;

int a[1000001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
    int n, p, q;
    cin >> p >> q;
    for (int i = 2; i <= 1000000; i++) a[i] = i;
    for (int i = 2; i <= 500000; i++) {
        if (!a[i]) continue;
        for (int j = 2 * i; j <= 1000000; j += i)
            a[j] = 0;
    }
    for (int i = p; i <= q; i++)
        if (a[i]) cout << a[i] << '\n';
}