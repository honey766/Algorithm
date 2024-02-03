#include <iostream>
using namespace std;

int f(int x, int y, int width, int r, int c, int s) {
    if (width == 1) return s;
    int swidth = width / 2;
    int xmid = x + swidth;
    int ymid = y + swidth;
    if (r < xmid && c < ymid) return f(x, y, swidth, r, c, s);
    else if (r < xmid && c >= ymid) return f(x, ymid, swidth, r, c, s + swidth * swidth);
    else if (r >= xmid && c < ymid) return f(xmid, y, swidth, r, c, s + 2 * swidth * swidth);
    else return f(xmid, ymid, swidth, r, c, s + 3 * swidth * swidth);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, r, c, num = 1;
    cin >> n >> r >> c;
    num <<= n;
    cout << f(0, 0, num, r, c, 0);
}