#include <iostream>
using namespace std;

int a[1000001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m, count;
    for (int i = 2; i <= 1000000; i++) a[i] = i;
    for (int i = 2; i <= 500000; i++) {
        if (!a[i]) continue;
        for (int j = 2 * i; j <= 1000000; j += i)
            a[j] = 0;
    }
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> m;
        count = 0;
        for (int j = 2; j <= m / 2; j++)
            if (a[j] && a[m - j]) count++;
        cout << count << '\n';
    }
}