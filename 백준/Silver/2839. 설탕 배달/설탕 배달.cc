#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    if (n % 5 == 0) cout << n / 5;
    else if (n % 10 == 1 || n % 10 == 3 || 
        n % 10 == 6 || n % 10 == 8 ) cout << n / 5 + 1;
    else if (n % 10 == 2 || (n % 10 == 4 && n != 4) ||
        (n % 10 == 7 && n != 7) || n % 10 == 9) cout << n / 5 + 2;
    else cout << "-1";
}