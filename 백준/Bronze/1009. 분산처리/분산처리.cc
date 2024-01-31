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
        b = (b % 4 == 0) ? 4 : b % 4; //모든 숫자는 최대 4 주기로 일의 자리가 같음
        while (--b > 0)
            tmp = (tmp * a) % 10;
        if (!tmp) tmp = 10;
        cout << tmp << '\n';
    }
}