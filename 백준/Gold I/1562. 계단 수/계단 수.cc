#include <iostream>
using namespace std;
#define N 1'000'000'000

int n;
int dp[100][10][1 << 10] = { 0, };
//dp[i][j][status] : i번째까지, i번째 숫자가 j, 지금까지 status 정보대로의 숫자를 씀

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int sum = 0;
    cin >> n;
    for (int i = 1; i < 10; ++i)
        dp[0][i][1 << i] = 1;
    for(int i = 1; i < n; ++i)
        for (int k = 0; k < (1 << 10); ++k){
            //i-1번째까지에서 j를 포함하거나(k | (1 << j)) j를 포함하지 않거나(k & ~(1 << j))
            dp[i][0][k | 1] = (dp[i - 1][1][k & ~1] + dp[i - 1][1][k | 1]) % N;
            for (int j = 1; j < 9; ++j)
                dp[i][j][k | (1 << j)] = ((dp[i - 1][j - 1][k & ~(1 << j)] + dp[i - 1][j - 1][k | (1 << j)]) % N +
                                         (dp[i - 1][j + 1][k & ~(1 << j)] + dp[i - 1][j + 1][k | (1 << j)]) % N) % N;
            dp[i][9][k | (1 << 9)] = (dp[i - 1][8][k & ~(1 << 9)] + dp[i - 1][8][k | (1 << 9)]) % N;
        }
    for (int i = 0; i < 10; ++i)
        sum = (sum + dp[n - 1][i][(1 << 10) - 1]) % N;
    cout << sum;
}