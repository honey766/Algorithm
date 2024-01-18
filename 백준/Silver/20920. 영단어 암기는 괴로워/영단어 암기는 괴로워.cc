#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Nilou {
    int count;
    string str;
};

bool comp(const Nilou a, const Nilou b) {
    if (a.count == b.count && a.str.size() == b.str.size())
        return a.str < b.str;
    if (a.count == b.count)
        return a.str.size() > b.str.size();
    return a.count > b.count;
}

const int SIZE = 160001;
const string NIL = "";

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
    return 1 + (n % 159013);
}

int insert_hash(Nilou* hash, Nilou n) {
    int h;
    for (int i = 0; i < SIZE / 2; i++) {
        h = (f1(n.str) + f2(n.str) * i) % SIZE;
        if (hash[h].str == n.str) {
            hash[h].count++; return -1;
        }
        if (hash[h].str == NIL) {
            hash[h] = n; return h;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m, h, dicSize;
    string s;
    vector<int> vec;
    Nilou* hash = new Nilou[SIZE]();
    cin >> n >> m;
    while (n--) {
        cin >> s;
        if (s.size() < m) continue;
        if ((h = insert_hash(hash, { 1, s })) != -1)
            vec.push_back(h);
    }
    dicSize = vec.size();
    Nilou* nahida = new Nilou[dicSize];
    for (int i = 0; i < dicSize; i++) nahida[i] = hash[vec[i]];
    sort(nahida, nahida + dicSize, comp);
    for (int i = 0; i < dicSize; i++) 
        cout << nahida[i].str << '\n';
}
