#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, n = 0;
    cin >> x;
    while (x > (++n) * (n + 1) / 2);
    x -= (n - 1) * n / 2; //x == 1 ~ n
    if (n % 2) cout << n + 1 - x << '/' << x;
    else cout << x << '/' << n + 1 - x;
}