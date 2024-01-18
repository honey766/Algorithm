#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, sqrta, isPrime, count = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a == 1) continue;
        sqrta = sqrt(a);
        isPrime = 1;
        for (int j = 2; j <= sqrta; j++)
            if (a % j == 0) { isPrime = 0; break; }
        count += isPrime;
    }
    cout << count;
}