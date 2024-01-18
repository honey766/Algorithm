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
 
    int bz1, bm1, bz2, bm2, gcd_;
    cin >> bz1 >> bm1 >> bz2 >> bm2;
    bz1 = bz1 * bm2 + bz2 * bm1;
    bm1 *= bm2;
    gcd_ = gcd(bz1, bm1);
    cout << bz1 / gcd_ << ' ' << bm1 / gcd_;
}