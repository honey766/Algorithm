#include <iostream>
#include <vector>
using namespace std;

//i가 끝점, 문자 n개로 팰린드롬 되는지 판별
bool isPal(const string& s, int i, int n) {
    bool check = true;
    for (int j = 0; j < n / 2; ++j) {
        if (s[i - j] != s[i - n + 1 + j]) {
            check = false;
            break;
        }
    }
    return check;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    int n = s.size();
    int* dp = new int[n + 1];
    vector<short>* arr = new vector<short>[n];

    for (int i = 1; i < n; ++i)
        for (int j = 2; j <= i + 1; ++j)
            if (isPal(s, i, j)) arr[i].push_back(j);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1] + 1;
        for (int a : arr[i - 1]) {
            dp[i] = min(dp[i], dp[i - a] + 1);
        }
    }
    cout << dp[n];
}