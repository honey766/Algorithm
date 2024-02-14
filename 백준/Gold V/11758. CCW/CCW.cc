#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int x[3], y[3];
    for (int i = 0; i < 3; ++i)
        cin >> x[i] >> y[i];
    int ccw = (x[1] - x[0]) * (y[2] - y[1]) - (x[2] - x[1]) * (y[1] - y[0]);
    if (!ccw) cout << 0;
    else cout << (ccw > 0 ? 1 : -1);
}