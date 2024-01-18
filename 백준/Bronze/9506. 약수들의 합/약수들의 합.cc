#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, sqrtn, len, perfectNum;
    while (true) {
        perfectNum = 0;
        vector<int> arr;
        cin >> n;
        if (n == -1) break;
        sqrtn = sqrt(n);
        for (int i = 1; i <= sqrtn; i++) {
            if (n % i == 0) {
                perfectNum += i + n / i;
                if (i == sqrtn && sqrtn * sqrtn == n)
                    perfectNum -= i;
                arr.push_back(i);
            }
        }
        len = arr.size();
        if (perfectNum != 2 * n) { cout << n << " is NOT perfect.\n"; continue; }
        cout << n << " = 1";
        for (int i = 1; i < 2 * len - 1; i++) {
            if (i < len) cout << " + " << arr[i];
            else if (!(i == len && sqrtn * sqrtn == n))
                cout << " + " << n / arr[2 * len - i - 1];
        }
        cout << '\n';
    }
}