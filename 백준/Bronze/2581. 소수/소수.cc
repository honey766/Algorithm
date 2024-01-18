#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, sqrti, isPrime, sum = 0, min = 10000;
    cin >> n >> m;
    for (int i = n; i <= m; i++) {
        if (i == 1) continue;
        sqrti = sqrt(i);
        isPrime = 1;
        for (int j = 2; j <= sqrti; j++)
            if (i % j == 0) { isPrime = 0; break; }
        if (isPrime) {
            sum += i;
            min = min > i ? i : min;
        }
    }
    if (min == 10000) cout << "-1";
    else cout << sum << '\n' << min;
}