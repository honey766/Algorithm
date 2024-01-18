#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, a, len, count = 1;
    queue<int> line;
    stack<int> rest;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a; line.push(a);
    }
    for (int i = 0; i < n; i++) {
        if (count == line.front())
            count++;
        else
            rest.push(line.front());
        line.pop();
        while(!rest.empty() && count == rest.top()){
            count++; rest.pop();
        }
    }
    len = rest.size();
    for (int i = 0; i < len; i++) {
        if (count == rest.top())
            count++;
        rest.pop();
    }
    if (count == n + 1) cout << "Nice";
    else cout << "Sad";
}