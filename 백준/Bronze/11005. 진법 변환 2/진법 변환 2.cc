#include <iostream>
#include <vector>
using namespace std;

char Invert(int n) {
    if (n < 10) return '0' + n;
    else return 'A' + n - 10;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num, b;
    vector<int> arr;
    cin >> num >> b;
    while (num > 0) {
        arr.push_back(num % b);
        num /= b;
    }
    for (int i = arr.size() - 1; i >= 0; i--)
        cout << Invert(arr[i]);
}