#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

short* parent;
bool check;

int Find(int a) {
    if (a == parent[a]) return a;
    else return parent[a] = Find(parent[a]);
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
    int v, e, a, b, c, sum = 0;
    cin >> v >> e;
    tuple<int, int, int>* graph = new tuple<int, int, int>[e];
    parent = new short[v + 1];
    for (int i = 1; i <= v; ++i)
        parent[i] = i;
    for(int i = 0; i < e; ++i) {
        cin >> a >> b >> c;
        graph[i] = make_tuple(c, a, b);
    }
    sort(graph, graph + e);
    
    for (int i = 0; i < e; ++i) {
        Union(get<1>(graph[i]), get<2>(graph[i]));
        if (check) sum += get<0>(graph[i]);
    }
    cout << sum;
}