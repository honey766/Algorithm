#include <iostream>
using namespace std;

short dp[1000][1000];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string s1, s2;
    int i, j, cnt;
    cin >> s1 >> s2;
    int n1 = s1.size(), n2 = s2.size();
    dp[0][0] = (s1[0] == s2[0]);
    for (i = 1; i < n1; i++) 
        dp[i][0] = (s1[i] == s2[0] ? 1 : dp[i - 1][0]);
    for (i = 1; i < n2; i++)
        dp[0][i] = (s1[0] == s2[i] ? 1 : dp[0][i - 1]);

    for (i = 1; i < n1; i++) {
        for (j = 1; j < n2; j++) {
            if (s1[i] == s2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    i = n1 - 1; j = n2 - 1; cnt = dp[i][j];
    string s;
    s.resize(cnt);
    cout << cnt << '\n';
    while (i > 0 && j > 0) {
        if (s1[i] == s2[j]) {
            s[--cnt] = s1[i];
            i--; j--;
        }
        else if (dp[i][j - 1] > dp[i - 1][j])
            j--;
        else 
            i--;
    }
    while (i >= 0) {//j == 0
        if (s1[i] == s2[0]) {
            s[0] = s2[0];
            break;
        }
        i--;
    }
    while (j >= 0) {//i == 0
        if (s1[0] == s2[j]) {
            s[0] = s1[0];
            break;
        }
        j--;
    }
    cout << s;
}