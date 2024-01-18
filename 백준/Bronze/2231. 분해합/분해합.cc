#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, digit = 0, temp, sum;
    cin >> n;
    temp = n;
    while (temp > 0) { temp /= 10; digit++; }
    for (int i = n - 9 * digit; i < n; i++) {
        if (i < 1) continue;
        temp = sum = i;
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }
        if (sum == n) { cout << i; return 0; }
    }
    cout << '0';
}