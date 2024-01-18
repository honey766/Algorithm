#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;
    while (cin >> a >> b >> c) {
        if (a == 0 && b == 0 && c == 0) break;
        if (2 * max(max(a, b), c) >= a + b + c) cout << "Invalid\n";
        else if (a == b && b == c) cout << "Equilateral\n";
        else if (a == b || b == c || c == a) cout << "Isosceles\n";
        else cout << "Scalene\n";
    }
}