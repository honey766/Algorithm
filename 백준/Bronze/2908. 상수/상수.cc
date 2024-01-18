#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a, b;
    cin >> a >> b;
    a = a - (a / 100 * 100 + a % 10) + (a % 10 * 100 + a / 100);
    b = b - (b / 100 * 100 + b % 10) + (b % 10 * 100 + b / 100);
    cout << (a > b ? a : b);
}