#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int n, m;
int* parent;
bool check;

int Find(int a) {
    if (a == parent[a]) return a;
    return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
    check = false;

    int A = Find(a);
    int B = Find(b);

    if (A == B) return;

    check = true;
    parent[A] = B;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //크루스칼
    int a, b, c, sum = 0, cnt = 0;
    cin >> n >> m;
    parent = new int[n + 1];
    tuple<short, int, int>* graph = new tuple<short, int, int>[m];
    for (int i = 1; i <= n; ++i)
        parent[i] = i;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        graph[i] = make_tuple(c, a, b);
    }
    sort(graph, graph + m);
    for (int i = 0; cnt < n - 2; ++i) {
        Union(get<1>(graph[i]), get<2>(graph[i]));
        if (check) {
            sum += get<0>(graph[i]);
            ++cnt;
        }
    }
    cout << sum;
}