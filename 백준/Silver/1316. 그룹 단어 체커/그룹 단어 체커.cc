#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, check, len, count = 0;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        int* arr = new int[26]();
        check = 1;
        len = s.length();
        for (int j = 0; j < len; j++) {
            if (arr[s[j] - 'a'] && s[j] != s[j - 1]) {
                check = 0; break;
            }
            else {
                arr[s[j] - 'a'] = 1;
            }
        }
        count += check;
    }
    cout << count;
}