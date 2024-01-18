#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x[3], y[3], newx, newy;
    for (int i = 0; i < 3; i++)
        cin >> x[i] >> y[i];
    if (x[0] == x[1]) newx = x[2];
    else if (x[0] == x[2]) newx = x[1];
    else newx = x[0];
    if (y[0] == y[1]) newy = y[2];
    else if (y[0] == y[2]) newy = y[1];
    else newy = y[0];
    cout << newx << ' ' << newy;
}