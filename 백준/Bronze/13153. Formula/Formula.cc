#include <iostream>
#include <cmath>
using namespace std;
#define POW(x) (x) * (x)

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int x[3], y[3];
    double a, b, c, A, r, inputR, percent;
    for (int i = 0; i < 3; i++)
        cin >> x[i] >> y[i];
    cin >> inputR;
    a = sqrt(POW(x[1] - x[0]) + POW(y[1] - y[0]));
    b = sqrt(POW(x[2] - x[0]) + POW(y[2] - y[0]));
    c = sqrt(POW(x[2] - x[1]) + POW(y[2] - y[1]));
    A = sqrt(4 * POW(a) * POW(b) - POW((POW(a) + POW(b) - POW(c)))) / 4;
    r = 2 * A / (a + b + c);
    percent = 100 * r / inputR;
    if (99.9995 < percent && percent < 100.0005) cout << '0';
    else cout << percent - 100;
}