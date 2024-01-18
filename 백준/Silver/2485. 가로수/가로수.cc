#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    int tmp;
    while (b > 0) {
        tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
    int n, prev, cur, gcd_, first, count = 0;
    cin >> n >> prev >> cur;
    gcd_ = cur - prev;
    first = prev;
    for (int i = 0; i < n - 2; i++) {
        prev = cur; cin >> cur;
        gcd_ = gcd(cur - prev, gcd_);
    }
    cout << (cur - first) / gcd_ - (n - 1);
}