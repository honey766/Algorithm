#include <iostream>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
#define MUL(n) (((n) * 2) % 10000)
#define SUB(n) ((n) == 0 ? 9999 : (n) - 1)
#define L(n) ((n) / 1000 + (n) % 1000 * 10)
#define R(n) ((n) / 10 + (n) % 10 * 1000)

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int tc, a, b, tmp, n;
    char visited[10000];
    cin >> tc;
    while (tc--) {
        memset(visited, 0, 10000);
        cin >> a >> b;
        queue<int> que;
        que.push(a);
        visited[a] = 1;
        while (!que.empty()) {
            n = que.front();
            if (n == b) break;
            que.pop();
            if (!visited[tmp = MUL(n)]) {
                que.push(tmp);
                if (n >= 5000) visited[tmp] = 'd';
                else visited[tmp] = 'D';
            }
            if (!visited[tmp = SUB(n)]) {
                que.push(tmp);
                visited[tmp] = 'S';
            }
            if (!visited[tmp = L(n)]) {
                que.push(tmp);
                visited[tmp] = 'L';
            }
            if (!visited[tmp = R(n)]) {
                que.push(tmp);
                visited[tmp] = 'R';
            }
        }
        stack<char> stk;
        int n2;
        while (n != a) {
            n2 = n;
            switch (visited[n]) {
            case 'd':
                visited[n] = 'D';
                n = n / 2 + 5000;
                break;
            case 'D':
                n /= 2;
                break;
            case 'S':
                n = (n == 9999) ? 0 : n + 1;
                break;
            case 'L':
                n = R(n);
                break;
            case 'R':
                n = L(n);
                break;
            } 
            stk.push(visited[n2]);
        }
        while (!stk.empty()) {
            cout << stk.top();
            stk.pop();
        }
        cout << '\n';
    }
}