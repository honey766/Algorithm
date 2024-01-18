#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
    set<string> sets;
    string s;
    cin >> s;
    int len = s.size();
    for (int i = 0; i < len; i++)
        for (int j = 1; j <= len - i; j++)
            sets.insert(s.substr(i, j));
    cout << sets.size();
}