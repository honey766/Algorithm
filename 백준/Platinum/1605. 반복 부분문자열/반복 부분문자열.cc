#include <iostream>
#include <algorithm>
using namespace std;

int* sa, * pos;
int n, d;
bool cmp(int i, int j) {
    if (pos[i] != pos[j]) return pos[i] < pos[j];
    i += d;
    j += d;
    return (i < n && j < n ? pos[i] < pos[j] : i > j);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    string s;
    cin >> n >> s;
    sa = new int[n];
    pos = new int[n];
    int* tmp = new int[n];
    int Max = 0;
    //접미사 배열
    for (int i = 0; i < n; i++) {
        sa[i] = i;
        pos[i] = s[i];
    }
    for (d = 1; ; d <<= 1) {
        sort(sa, sa + n, cmp);
        tmp[0] = 0;
        for (int i = 1; i < n; i++)
            tmp[i] = tmp[i - 1] + cmp(sa[i - 1], sa[i]);
        for (int i = 0; i < n; i++)
            pos[sa[i]] = tmp[i];
        if (tmp[n - 1] == n - 1) break;
    }
    //LCP 배열
    int k = 0;
    for (int i = 0; i < n; i++) {
        int idx = pos[i];
        if (idx == n - 1)continue;

        int j = sa[idx + 1];
        while (i + k < n && j + k < n) {
            if (s[i + k] != s[j + k]) break;
            k++;
        }

        Max = max(Max, k);
        k = max(k - 1, 0);
    }
    cout << Max;
}