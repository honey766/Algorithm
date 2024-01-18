#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
    int k, i, len, pal;
    string s;
    cin >> k;
    while (k--) {
        cin >> s; len = s.size();
        pal = 1;
        for (i = 0; i < len / 2; i++)
            if (s[i] != s[len - 1 - i]) {
                pal = 0; break;
            }
        cout << pal << ' ' << i + 1 << '\n';
    }
}