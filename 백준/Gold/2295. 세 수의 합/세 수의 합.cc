#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, d, Max = -1;
    cin >> n;
    int* vec = new int[n * n];
    int* u = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> u[i];
    sort(u, u + n);
    //x+y+z == k, x+y == k-z
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            vec[n * i + j] = u[i] + u[j];
    sort(vec, vec + n * n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            d = lower_bound(vec, vec + n * n, u[j] - u[i]) - vec;
            if (vec[d] == u[j] - u[i])
                Max = max(Max, u[j]);
        }
    }
    cout << Max;
}