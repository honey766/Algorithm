#include <iostream>
#include <unordered_map>
using namespace std;

int stotoi(string s) {
    int len = s.size();
    int num = 0;
    int digit = 1;
    for (int i = len - 1; i >= 0; i--) {
        if (s[i] < '0' || '9' < s[i])
            return -1;
        else {
            num += (s[i] - '0') * digit;
            digit *= 10;
        }
    }
    return num;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    int n, m, num;
    cin >> n >> m;
    string* s = new string[n];
    unordered_map<string, int> mapset;
    string input;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        mapset.insert({ s[i], i + 1 });
    }
    for (int i = 0; i < m; i++) {
        cin >> input;
        if ((num = stotoi(input)) == -1)
            cout << mapset[input] << '\n';
        else 
            cout << s[num - 1] << '\n';
    }
}