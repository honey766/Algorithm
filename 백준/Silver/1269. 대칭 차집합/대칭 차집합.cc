#include <iostream>
using namespace std;

const int SIZE = 400109;
const int NIL = 100000001;

int f1(int n) {
    return n % SIZE;
}

int f2(int n) {
    return 1 + (n % 400009);
}

int insert_hash(int* hash, int n) {
    int h;
    for (int i = 0; i < SIZE / 2; i++) {
        h = (f1(n) + f2(n) * i) % SIZE;
        if (hash[h] == n) return -1;
        if (hash[h] == NIL) {
            hash[h] = n; return 1;
        }
    }
    return -1;
}

int search_hash(int* hash, int n) {
    int h;
    for (int i = 0; i < SIZE / 2; i++) {
        h = (f1(n) + f2(n) * i) % SIZE;
        if (hash[h] == NIL )
            return 0;
        if (hash[h] == n)
            return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m, a, count = 0;
    cin >> n >> m;
    int* hash = new int[SIZE];
    for (int i = 0; i < SIZE; i++) hash[i] = NIL;
    for (int i = 0; i < n; i++) {
        cin >> a;
        insert_hash(hash, a);
    }
    for (int i = 0; i < m; i++) {
        cin >> a;
        count += search_hash(hash, a);
    }
    cout << n + m - 2 * count;
}