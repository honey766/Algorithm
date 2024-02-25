#include <iostream>
using namespace std;

int* parent;

int Find(int a) {
    if (a == parent[a]) return a;
    return parent[a] = Find(parent[a]);
}

bool Union(int a, int b) {
    int A = Find(a);
    int B = Find(b);

    if (A == B) return true;

    parent[A] = B;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m, a, b;
    cin >> n >> m;
    parent = new int[n];
    for (int i = 0; i < n; i++)
        parent[i] = i;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        if (Union(a, b)) {
            cout << i;
            return 0;
        }
    }
    cout << 0;
}