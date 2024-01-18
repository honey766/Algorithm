#include <iostream>
#include <unordered_set>
using namespace std;

#include <iostream>
using namespace std;

const int SIZE = 261983;
const string NIL = "";

struct Pair {
    string s;
    int enter;
};

int f1(string s) {
    int i, n = 0, len = s.size();
    if (len % 2) {
        for (i = 0; i < len - 1; i += 2)
            n += (int)s[i] * (23 * s[i + 1] * (i + 2) * (i + 5) + 2);
        n += (int)s[i] * (23 * i * (i + 1) * (i + 5) + 2);
    }
    else {
        for (i = 0; i < len; i += 2)
            n += (int)s[i] * (23 * s[i + 1] * (i + 2) * (i + 5) + 2);
    }
    return n % SIZE;
}

int f2(string s) {
    int i, n = 0, len = s.size();
    if (len % 2) {
        for (i = 0; i < len - 1; i += 2)
            n += (int)s[len - i - 1] * (23 * s[len - i - 2] * (i + 2) * (i + 5) + 2);
        n += (int)s[len - i - 1] * (23 * i * (i + 1) * (i + 5) + 2);
    }
    else {
        for (i = 0; i < len; i += 2)
            n += (int)s[len - i - 1] * (23 * s[len - i - 2] * (i + 2) * (i + 5) + 2);
    }
    return 1 + (n % 260999);
}

int insert_hash(Pair* hash, Pair p) {
    int h;
    for (int i = 0; i < SIZE / 2; i++) {
        h = (f1(p.s) + f2(p.s) * i) % SIZE;
        if (hash[h].s == p.s) {
            if (hash[h].enter == p.enter) return 0;
            hash[h].enter = p.enter; return 1;
        }
        if (hash[h].s == NIL) {
            hash[h] = p; return 1;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, count = 0, enterNum = 0;
    string s;
    Pair* hash = new Pair[SIZE]();
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s == "ENTER") {
            enterNum++;
            continue;
        }
        Pair p = { s, enterNum };
        count += insert_hash(hash, p);
    }
    cout << count;
}