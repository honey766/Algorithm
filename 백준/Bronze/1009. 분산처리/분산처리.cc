#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t, a, b, tmp;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        tmp = a % 10;
        while (--b)
            tmp = (tmp * a) % 10;
        if (!tmp) tmp = 10;
        cout << tmp << '\n';
    }
}