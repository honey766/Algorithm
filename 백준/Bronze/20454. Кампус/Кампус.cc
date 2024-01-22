#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n, k, x, y, col, cycle, a, cNum;
    cin >> n >> k >> x >> y;
    col = (n / k) * x + (n - n / k) * y;
    cycle = (k - 1) * y + x;
    int tc; cin >> tc;
    while (tc--) {
        cin >> a;
        a %= col;
        if (a == 0) a = col;

        cNum = (a / cycle) * k;
        a %= cycle;
        if (a == 0) a = -y + 1;

        if (a <= (k - 1) * y) cout << cNum + (a - 1) / y + 1 << '\n';
        else cout << cNum + k << '\n';
    }
}