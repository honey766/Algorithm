#include <iostream>
#include <algorithm>
using namespace std;

bool incr(const string a, const string b) {
    if (a.length() == b.length()) return a < b;
    else return a.length() < b.length();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string* s = new string[n];
    for (int i = 0; i < n; i++) cin >> s[i];
    sort(s, s + n, incr);
    for (int i = 0; i < n; i++) 
        if(i == 0 || (i > 0 && s[i] != s[i - 1]))
            cout << s[i] << '\n';
}