#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct pr {
    short i;
    short j;
    pr() {}
    pr(short I, short J) : i(I), j(J) {}
};

pr hashs[400000][2];
char cnt[400000];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    memset(cnt, 0, 400000);
    int n, w, a, b, c, d;
    cin >> w >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j) {
            int tmp = arr[i] + arr[j];
            if (cnt[tmp] >= 2) cnt[tmp] = 3;
            else hashs[tmp][cnt[tmp]++] = pr(i, j);
        }
    for (int i = 3; i < 400000; ++i) {
        int tmp = w - i;
        if (tmp < 3 || 399999 < tmp || !cnt[i] || !cnt[tmp]) continue;
        if (cnt[i] > 2 || cnt[tmp] > 2) {
            cout << "YES";
            return 0;
        }
        for (int j = 0; j < cnt[i]; ++j)
            for (int k = 0; k < cnt[tmp]; ++k) {
                a = hashs[i][j].i;
                b = hashs[i][j].j;
                c = hashs[tmp][k].i;
                d = hashs[tmp][k].j;
                if (a != c && a != d && b != c && b != d) {
                    cout << "YES";
                    return 0;
                }
            }
    }
    cout << "NO";
}