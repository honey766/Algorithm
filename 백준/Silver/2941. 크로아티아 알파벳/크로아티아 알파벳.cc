#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int i = 0, count = 0, n = s.length();
    while (i < n) {
        if (  (i < n - 1) && 
              (s[i] == 'c' && (s[i + 1] == '=' || s[i + 1] == '-') || s[i] == 'd' && s[i + 1] == '-' ||
              (s[i] == 'l' || s[i] == 'n') && s[i + 1] == 'j' || s[i] == 's' && s[i + 1] == '=' ||
              s[i] == 'z' && s[i + 1] == '=')) {
            i += 2; count++;
        }
        else if ((i < n - 2) && (s[i] == 'd' && s[i + 1] == 'z' && s[i + 2] == '=')) {
            i += 3; count++;
        }
        else {
            i++; count++;
        }
    }
    cout << count;
}