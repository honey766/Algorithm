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


int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m, a, b;
    cin >> n >> m;
    if (m == 1) {
        cout << "YES"; return 0;
    }
    parent = new int[n];
    Rank = new int[n]();
    for (int i = 0; i < n; i++) parent[i] = i;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a;
            if (a == 1 && i < j) Union(i, j); //갈 수 있는 애들끼리 하나의 집합에 모음
        }
    }
    cin >> b;
    while (--m) {
        a = b;
        cin >> b;
        if (Find(a - 1) != Find(b - 1)) { //서로 다른 집합에 있다면
            cout << "NO"; return 0;
        }
    }
    cout << "YES";
}