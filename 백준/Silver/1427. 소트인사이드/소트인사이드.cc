#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int n, temp;
    int digit = 0;
    short *arr;
    cin >> n;
    temp = n;
    while (temp >= 1) {
        digit++;
        temp /= 10;
    }
    arr = new short[digit];
    for (int i = 0; i < digit; i++) {
        arr[i] = n % 10;
        n /= 10;
    }
    sort(arr, arr + digit);
    for (int i = digit - 1; i >= 0; i--) cout << arr[i];
}