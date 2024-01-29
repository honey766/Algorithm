#include <iostream>
using namespace std;

int* parent;
int* Rank;

//Find와 Union은 각각 root를 빨리 찾도록 최적화
int Find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
    int A = Find(a);
    int B = Find(b);

    if (A == B) return;

    if (Rank[A] < Rank[B]) parent[A] = B;
    else if (Rank[A] > Rank[B]) parent[B] = A;
    else {
        parent[B] = A;
        Rank[A]++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int a, b, n, m;
    cin >> n >> m;
    parent = new int[n + 1];
    Rank = new int[n + 1]();
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    while (m--) {
        cin >> a >> b;
        Union(a, b);
    }
    a = 0;
    for (int i = 2; i <= n; i++) 
        if (Find(1) == Find(i)) ++a;
    cout << a;
}