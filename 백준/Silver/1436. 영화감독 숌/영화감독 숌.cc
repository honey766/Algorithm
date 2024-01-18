#include <iostream>
using namespace std;

int IsDevil(int n) {
    int continuous = 0;
    while (n > 0) {
        if (n % 10 == 6) continuous++;
        else continuous = 0;
        if (continuous == 3) return 1;
        n /= 10;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, count = 0;
    long long int i = 665;
    cin >> n;
    while (++i) {
        if (IsDevil(i)) count++;
        if (count == n) { cout << i; break; }
    }
}