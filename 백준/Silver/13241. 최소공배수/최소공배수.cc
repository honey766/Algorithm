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
 
    long long int a, b;
    cin >> a >> b;
    cout << a / gcd(a, b) * b << '\n';
}