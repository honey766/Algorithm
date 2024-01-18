#include <iostream>
using namespace std;

long long int gcd(long long int a, long long int b)
{
    long long int tmp;
    while (b > 0) {
        tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    long long int prev, cur, gcd_;
    cin >> n >> cur;
    gcd_ = cur;
    for (int i = 0; i < n - 1; i++) {
        prev = cur;
        cin >> cur;
        gcd_ = gcd(gcd_, cur);
        cur = cur / gcd(prev, cur) * prev;
    }
    cout << cur * gcd_;
}