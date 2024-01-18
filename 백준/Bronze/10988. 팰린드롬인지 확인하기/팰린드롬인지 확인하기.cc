#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    int p = 1;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) {
            p = 0; break;
        }
    }
    cout << p;
}