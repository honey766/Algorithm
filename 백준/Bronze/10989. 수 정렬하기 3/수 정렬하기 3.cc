#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, count = 1, index[10001] = { 0, };
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        index[a]++;
    }
    for (int i = 2; i <= 10000; i++) index[i] += index[i - 1];
    for (int i = 1; i <= n; i++) {
        if (i <= index[count]) cout << count << '\n';
        else { count++; i--; }
    }
}