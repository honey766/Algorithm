#include <iostream>
#include <string>
#include <stack>
using namespace std;

int parentheses(char c) {
    if (c == '(' || c == '[') return 1;
    else if (c == ')' || c == ']') return 2;
    else return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string s;
    int len;
    while (true) {
        getline(cin, s);
        if (s == ".") break;
        len = s.size();
        stack<char> st;
        bool isCorrect = true;
        for (int i = 0; i < len; i++) {
            if (!parentheses(s[i])) continue;
            if (parentheses(s[i]) == 1) {
                st.push(s[i]); continue;
            }
            if (!st.empty() && (s[i] == ')' && st.top() == '(' || s[i] == ']' && st.top() == '['))
                st.pop();
            else {
                isCorrect = false; break;
            }
        }
        if (isCorrect && st.empty()) cout << "yes\n";
        else cout << "no\n";
    }
}