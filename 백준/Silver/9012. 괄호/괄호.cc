#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, len, stack = 0;
    bool vps;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s; len = s.size();
        vps = true; stack = 0;
        for (int j = 0; j < len; j++) {
            if (s[j] == '(') stack++;
            else if(s[j] == ')') {
                if (stack == 0) {
                    vps = false; break;
                }
                stack--;
            }
        }
        if (stack == 0 && vps) cout << "YES\n";
        else cout << "NO\n";
    }
}