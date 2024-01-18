#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    string s;
    set<string> nohear;
    set<string> nohearlook;
    for (int i = 0; i < n; i++) {
        cin >> s; nohear.insert(s);
    }
    for (int i = 0; i < m; i++) {
        cin >> s;
        if (nohear.find(s) != nohear.end()) //finded
            nohearlook.insert(s);
    }
    cout << nohearlook.size() << '\n';
    for (auto iter = nohearlook.begin(); iter != nohearlook.end(); iter++)
        cout << *iter << '\n';
}