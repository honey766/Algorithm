#include <iostream>
#include <cmath>
using namespace std;

int IsPrime(int n) {
    int sqrtn = sqrt(n);
    int isPrime = 1;
    for (int i = 2; i <= sqrtn; i++)
        if (n % i == 0) { isPrime = 0; break; }
    return isPrime;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, sqrtn, isPrime, sum = 0, min = 10000;
    cin >> n;
    sqrtn = sqrt(n);
    for (int i = 2; i <= sqrtn; i++) {
        if (IsPrime(n)) break;
        if (!IsPrime(i)) continue;
        if (n % i == 0) {
            n /= i;
            cout << i << '\n';
            sqrtn = sqrt(n);
            i--;
        }
    }
    if(n != 1) cout << n;
}