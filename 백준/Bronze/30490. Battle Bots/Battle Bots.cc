#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int cnt = 1;
    long long n = 1, num;
    cin >> num;
    while (n < num) {
        n <<= 1;
        ++cnt;
    }
    cout << cnt;
}