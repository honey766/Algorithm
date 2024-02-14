#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t, n, m;
    long long cnt = 0;
    cin >> t >> n;
    int* a = new int[n + 1];
    a[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    cin >> m;
    int* b = new int[m + 1];
    b[0] = 0;
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
        b[i] += b[i - 1];
    }

    int N = n * (n + 1) / 2;
    int M = m * (m + 1) / 2;
    int* A = new int[N];
    int* B = new int[M];
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; ++j)
            A[cnt++] = a[j] - a[i - 1];
    cnt = 0;
    for (int i = 1; i <= m; ++i)
        for (int j = i; j <= m; ++j)
            B[cnt++] = b[j] - b[i - 1];

    if (N > M) {
        int tmp = N, *tmp2 = A;
        N = M;       A = B;
        M = tmp;     B = tmp2;
    }
    sort(B, B + M);
    //여기까지 밑작업

    cnt = 0;
    for (int i = 0; i < N; ++i) {
        int target = t - A[i];
        cnt += upper_bound(B, B + M, target) - lower_bound(B, B + M, target);
    }
    cout << cnt;
}