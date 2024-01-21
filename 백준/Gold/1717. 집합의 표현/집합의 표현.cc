#include <iostream>
using namespace std;

int* parent;
int* Rank;
int n;

void initial() {
    for (int i = 0; i < n; i++)
        parent[i] = i;
}

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

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int m, a, b, c;
    cin >> n >> m;
    n++;
    parent = new int[n];
    Rank = new int[n]();
    initial();
    while (m--) {
        cin >> c >> a >> b;
        if (c) { //같은 집합에 포함되어 있는지
            if (Find(a) == Find(b)) cout << "YES\n";
            else cout << "NO\n";
        }
        else { //합집합
            Union(a, b);
        }
    }
}