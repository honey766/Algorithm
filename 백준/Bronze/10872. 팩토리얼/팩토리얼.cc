#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, fact = 1;
    cin >> n;
    for (int i = 2; i <= n; i++)
        fact *= i;
    cout << fact;
}