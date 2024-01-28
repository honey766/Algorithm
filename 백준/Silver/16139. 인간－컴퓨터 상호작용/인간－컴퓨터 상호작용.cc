#include <iostream>
using namespace std;

int sum[200001][26]; //sum[i][j] : i-1번째 문자열까지, ('a' + j) 문자가 sum[i][j]개 있다

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string s;
    char c; 
    int q, i, j;
    cin >> s >> q;
    int n = s.size();
    for (j = 0; j < 26; j++) sum[0][j] = 0;
    for (i = 1; i <= n; i++) 
        for (j = 0; j < 26; j++) 
            sum[i][j] = sum[i - 1][j] + ((s[i - 1] - 'a' == j) ? 1 : 0);
    while (q--) {
        cin >> c >> i >> j;
        cout << sum[j + 1][c - 'a'] - sum[i][c - 'a'] << '\n';
    }
}