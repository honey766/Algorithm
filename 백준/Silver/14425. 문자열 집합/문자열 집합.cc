#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m, count = 0;
    cin >> n >> m;
    string s;
    unordered_set<string> a;
    for (int i = 0; i < n; i++) {
        cin >> s; a.insert(s);
    }
    for (int i = 0; i < m; i++) {
        cin >> s;
        if (a.find(s) != a.end())
            count++;
    }
    cout << count;     
}