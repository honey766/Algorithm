#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, a;
    cin >> n;
    char* t = new char[n];
    short* p = new short[n];
    int* dp = new int[n + 1]();
    for (int i = 0; i < n; ++i) {
        cin >> a >> p[i];
        t[i] = a;
    }

    dp[t[0]] = p[0];
    for (int i = 1; i < n; ++i) {
        dp[i] = max(dp[i], dp[i - 1]);
        int tmp = i + t[i];
        if (tmp <= n)
            dp[tmp] = max(dp[tmp], dp[i] + p[i]);
    }
    cout << max(dp[n - 1], dp[n]);
}