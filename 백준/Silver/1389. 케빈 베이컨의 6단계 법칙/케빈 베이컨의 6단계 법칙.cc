#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int n;
vector<int> graph[100];
bool visited[100];

int bfs(int i) {
    int cnt = 0, sum = 0;
    memset(visited, 0, 100);
    queue<int> que;
    que.push(i);
    visited[i] = true;
    while (!que.empty()) {
        ++cnt;
        int sz = que.size();
        while (sz--) {
            int a = que.front();
            que.pop();
            for (int b : graph[a]) {
                if (visited[b]) continue;
                que.push(b);
                visited[b] = true;
                sum += cnt;
            }
        }
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int m, a, b, MinIdx, Min = 10000;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }
    for (int i = 0; i < n; ++i) {
        a = bfs(i);
        if (a < Min) {
            Min = a;
            MinIdx = i + 1;
        }
    }
    cout << MinIdx;
}