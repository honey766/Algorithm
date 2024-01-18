#include <iostream>
using namespace std;

int ToDecimal(char c) {
    if ('0' <= c && c <= '9') return c - '0';
    else return c - 'A' + 10;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int b, num = 0, currentDigit = 1;
    cin >> s >> b;
    for (int i = s.size() - 1; i >= 0; i--) {
        num += ToDecimal(s[i]) * currentDigit;
        currentDigit *= b;
    }
    cout << num;
}