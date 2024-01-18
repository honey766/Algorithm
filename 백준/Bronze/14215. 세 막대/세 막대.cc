#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, maxN;
    cin >> a >> b >> c;
    maxN = max(max(a, b), c);
    if (2 * maxN >= a + b + c)
        cout << 2 * (a + b + c - maxN) - 1;
    else cout << a + b + c;
}