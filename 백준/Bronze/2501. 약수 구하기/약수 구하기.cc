#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, sqrtn, count = 0;
    cin >> n >> k;
    sqrtn = sqrt(n);
    for (int i = 1; i <= sqrtn; i++) {
        if (n % i == 0) count++;
        if (k == count) {
            cout << i; return 0;
        }
    }
    if ((k > 2 * count) || (sqrtn * sqrtn == n && k > 2 * count - 1)) { 
        cout << '0'; return 0;
    }
    if (sqrtn * sqrtn == n) count--;
    for (int i = sqrtn; i > 0; i--) {
        if (n % i == 0) count++;
        if (k == count) {
            cout << n / i; return 0;
        }
    }
}