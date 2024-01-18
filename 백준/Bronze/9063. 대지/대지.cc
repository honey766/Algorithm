#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, y;
    int minx = 100000, miny = 100000, maxx = -100000, maxy = -100000;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        if (x < minx) minx = x;
        if (x > maxx) maxx = x;
        if (y < miny) miny = y;
        if (y > maxy) maxy = y;
    }
    cout << (maxx - minx) * (maxy - miny);
}