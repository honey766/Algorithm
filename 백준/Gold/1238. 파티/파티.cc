#include <iostream>
#include <queue>
#include <functional>
using namespace std;
#define INF 2'000'000'000
#define pr pair<int, int>

int n, m, x;

void dijkstra(vector<vector<pr>>& graph, int* dist) {
    priority_queue<pr, vector<pr>, greater<pr>> pq;
    int curNode, curDist;

    for (int i = 0; i < n; i++) 
        dist[i] = INF;

    dist[x] = 0;
    pq.push({ 0, x });
    while (!pq.empty()) {
        curDist = pq.top().first;
        curNode = pq.top().second;
        pq.pop();

        if (curDist != dist[curNode]) continue;

        int len = graph[curNode].size();
        for (int i = 0; i < len; i++) {
            int nodeNum = graph[curNode][i].first;
            int nodeDist = graph[curNode][i].second;

            if (dist[nodeNum] > dist[curNode] + nodeDist) {
                dist[nodeNum] = dist[curNode] + nodeDist;
                pq.push({ dist[nodeNum], nodeNum });
            }
        }
    }
}


int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int a, b, c;
    cin >> n >> m >> x;
    x--;

    vector<vector<pr>> graph(n);
    vector<vector<pr>> graph2(n);
    while (m--) {
        cin >> a >> b >> c;
        graph[a - 1].emplace_back(b - 1, c);
        graph2[b - 1].emplace_back(a - 1, c);
    }

    int* dist1 = new int[n];
    int* dist2 = new int[n];

    dijkstra(graph, dist1);
    dijkstra(graph2, dist2);

    int Max = -1;
    for (int i = 0; i < n; i++)
        Max = max(Max, dist1[i] + dist2[i]);

    cout << Max;
}