#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, max = -1, idx = -1;
    for (int i = 0;i < 81; i++) {
        cin >> a;
        if (a > max) {
            max = a; idx = i;
        }
    }
    cout << max << '\n' << idx / 9 + 1 << ' ' << idx % 9 + 1;
}