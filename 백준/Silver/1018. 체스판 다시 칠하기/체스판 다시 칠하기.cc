#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, min = 64, count;
    char base;
    cin >> n >> m;
    string* s = new string[n];
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i <= n - 8; i++) {
        for (int j = 0; j <= m - 8; j++) {
            count = 0;
            base = s[i][j];
            for (int k = 0; k < 8; k++)
                for (int l = 0; l < 8; l++)
                    if (((k + l) % 2) && base == s[i + k][j + l] ||
                        !((k + l) % 2) && base != s[i + k][j + l])
                        count++;
            if (count > 32) count = 64 - count;
            min = min > count ? count : min;
        }
    }
    cout << min;
}