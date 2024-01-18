#include <iostream>
using namespace std;

const int SIZE = 32003;
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
    return 1 + (n % 31511);
}

int insert_hash(string* hash, string s) {
    int h;
    for (int i = 0; i < SIZE / 2; i++) {
        h = (f1(s) + f2(s) * i) % SIZE;
        if (hash[h] == s) return 0;
        if (hash[h] == NIL) {
            hash[h] = s; return 1;
        }
    }
    return 0;
}

char search_hash(string* hash, string s) {
    int h;
    for (int i = 0; i < SIZE / 2; i++) {
        h = (f1(s) + f2(s) * i) % SIZE;
        if (hash[h] == NIL)
            return 0;
        if (hash[h] == s)
            return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, count = 1;
    string s1, s2;
    string* hash = new string[SIZE](); //춤추는 애들
    insert_hash(hash, "ChongChong");
    cin >> n;
    while (n--) {
        cin >> s1 >> s2;
        char find1 = search_hash(hash, s1), find2 = search_hash(hash, s2);
        if (!(find1 ^ find2)) continue;
        else {
            count++;
            if (find1) insert_hash(hash, s2);
            else insert_hash(hash, s1);
        }
    }
    cout << count;
}