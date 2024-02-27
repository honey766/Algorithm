#include <iostream>
#include <tuple>
#include <algorithm>
#include <cmath>
using namespace std;
#define f(x, y) ((x.first - y.first)*(x.first - y.first) + (x.second - y.second)*(x.second - y.second))

int* parent;
int Find(int a) {
    if (a == parent[a]) return a;
    return parent[a] = Find(parent[a]);
}

bool Union(int a, int b) {
    int A = Find(a);
    int B = Find(b);

    if (A == B) return false;

    parent[A] = B;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cout << fixed;
    cout.precision(2);
    int n, e, cnt;
    float a, b;
    cin >> n;
    e = n * (n + 1) / 2;
    parent = new int[n];
    tuple<float, int, int>* graph = new tuple<float, int, int>[e];
    pair<float, float>* arr = new pair<float, float>[n];

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        arr[i] = {a, b};
    }
    cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            float dist = sqrt(f(arr[i], arr[j]));
            graph[cnt++] = { dist, i, j };
        }
    sort(graph, graph + e);

    for (int i = 0; i < n; i++)
        parent[i] = i;
    a = cnt = 0;
    for (int i = 0; i < e && cnt < n - 1; i++)
        if (Union(get<1>(graph[i]), get<2>(graph[i]))) {
            cnt++;
            a += get<0>(graph[i]);
        }
    cout << a;
}