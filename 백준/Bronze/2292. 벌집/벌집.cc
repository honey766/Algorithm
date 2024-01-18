#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n = 0;
    cin >> t;
    while (t > 3 * (++n) * (n - 1) + 1);
    cout << n;
}