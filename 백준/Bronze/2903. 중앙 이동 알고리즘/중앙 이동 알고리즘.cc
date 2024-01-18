#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, pow = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
        pow *= 2;
    cout << (pow + 1) * (pow + 1);
}