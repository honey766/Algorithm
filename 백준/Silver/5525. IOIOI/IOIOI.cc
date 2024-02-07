#include <iostream>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m, cnt, totalCnt;
    char T[2] = { 'I', 'O' };
    string s;
    cin >> n >> m >> s;
    totalCnt = cnt = 0;

    for (int i = 0; i < m; ++i) {
        if (s[i] == T[cnt % 2]) {
            ++cnt;
            if (cnt == 2 * n + 1) {
                ++totalCnt;
                cnt -= 2;
            }
        }
        else cnt = (s[i] == 'I' ? 1 : 0);
    }
    cout << totalCnt;
}