#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, dp[1000];
    dp[0] = 1; dp[1] = 2;
    for (int i = 2; i < 1000; i++) 
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    cin >> n;
    cout << dp[n - 1];
}