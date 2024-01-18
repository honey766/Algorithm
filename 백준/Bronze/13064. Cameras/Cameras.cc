#include <iostream>
using namespace std;

bool isDig(char c) {
    return '1' <= c && c <= '9';
}

bool isDigitS(string s) {
    return isDig(s[0]) && isDig(s[2]) && isDig(s[3]) && isDig(s[5]) && isDig(s[6]) && isDig(s[7]);
}

bool isAlpha(char c) {
    return 'A' <= c && c <= 'Z';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    string s;
    cin >> n;
    while (n--) {
        cin >> s;
        if (isDigitS(s) && s[0] == s[1] && isAlpha(s[4]))
            cout << s << '\n';
    }
}