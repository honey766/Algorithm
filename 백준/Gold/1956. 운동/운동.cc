#include <iostream>
using namespace std;
#define INF 1'000'000'000

int w[400][400];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m, a, b, c, Min;;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            w[i][j] = INF;
    while (m--) {
        cin >> a >> b >> c;
        a--; b--;
        w[a][b] = min(w[a][b], c);
    }
    for (int i = 0; i < n; i++)
        w[i][i] = 0;

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                w[i][j] = min(w[i][j], w[i][k] + w[k][j]);

    Min = INF;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j)
                Min = min(Min, w[i][j] + w[j][i]);
    if (Min == INF) cout << "-1";
    else cout << Min;
}