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
 
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << a * b / gcd(a, b) << '\n';
    }
}