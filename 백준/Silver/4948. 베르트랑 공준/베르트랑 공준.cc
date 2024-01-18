#include <iostream>
using namespace std;

int a[246912];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
    int n, count;
    for (int i = 2; i <= 246912; i++) a[i] = i;
    for (int i = 2; i <= 123456; i++) {
        if (!a[i]) continue;
        for (int j = 2 * i; j <= 246912; j += i)
            a[j] = 0;
    }
    cin >> n;
    while (n > 0) {
        count = 0;
        for (int i = n + 1; i <= 2 * n; i++)
            if (a[i]) count++;
        cout << count << '\n';
        cin >> n;
    }
}