#include <iostream>
using namespace std;

double arr[10000];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cout << fixed;
    cout.precision(2);
    int k, n, m, T, t, tmp1;
    double Y, N, tmp2;
    char c;
    cin >> k;
    for (int ds = 1; ds <= k; ++ds) {
        Y = N = 0;
        cin >> n >> m >> T;
        for (int i = 0; i < n; ++i)
            arr[i] = 0;
        while (m--) {
            cin >> tmp1 >> t >> tmp2;
            if (0 <= T - t && T - t < 1000)
                arr[tmp1 - 1] += tmp2;
        }
        for (int i = 0; i < n; ++i) {
            cin >> c;
            if (c == 'N') N += 1.0 / (1 + arr[i] / 10000);
            else Y += 1;
        }
        cout << "Data Set " << ds << ":\n";
        cout << Y << ' ' << N << '\n';
        if (ds != k) cout << '\n';
    }
}