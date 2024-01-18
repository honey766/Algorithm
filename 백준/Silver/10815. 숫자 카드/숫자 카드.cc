#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int SIZE = 1048573;
int NIL = 10000001;

int f1(int n) {
    return (n + 10000000) % SIZE;
}

int f2(int n) {
    return 1 + ((n + 10000000) % 500977);
}

int insert_hash(int* hash, int n) {
    int h;
    for (int i = 0; i < SIZE / 2; i++) {
        h = (f1(n) + f2(n) * i) % SIZE;
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
        if (hash[h] == NIL) 
            return 0;
        if (hash[h] == n)
            return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, a;
    cin >> n;
    int* hash = new int[SIZE];
    for (int i = 0; i < SIZE; i++) hash[i] = NIL;
    for (int i = 0; i < n; i++) { 
        cin >> a; insert_hash(hash, a);
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        cout << search_hash(hash, a) << ' ';
    }
}