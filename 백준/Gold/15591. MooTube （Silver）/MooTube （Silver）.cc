#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<vector<pair<int, int>>> graph;

int BFS(int v, int k)
{
    int result = 0;
    vector<bool> visit(N + 1, false);
    queue<int> que;
    que.push(v);
    visit[v] = true;
    while (!que.empty()) {
        int v = que.front();
        que.pop();

        for (pair<int, int> pr : graph[v]) {
            if (!visit[pr.first] && pr.second >= k) {
                result++;
                que.push(pr.first);
                visit[pr.first] = true;
            }
        }
    }
    return result;
}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int Q, p, q, r, k, v;
    cin >> N >> Q;
    graph.resize(N + 1);
    for (int i = 0; i < N - 1; i++) {
        cin >> p >> q >> r;
        graph[p].push_back({ q, r });
        graph[q].push_back({ p, r });
    }
    for (int i = 0; i < Q; i++) {
        cin >> k >> v;
        cout << BFS(v, k) << '\n';
    }
}