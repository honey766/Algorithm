#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 500'000'000
#define pr pair<int, int>

vector<vector<pr>> graph;
int* dist;
int v;

void dijkstra(int k) {
    for (int i = 0; i < v; i++)
        dist[i] = INF;
    priority_queue<pr> pq;
    pq.push({ 0, k  });
    dist[k] = 0;
    while (!pq.empty()) {
        int cur_dist = -pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if (dist[cur_node] != cur_dist) continue;

        for (pr p : graph[cur_node]) {
            int nxt_dist = dist[cur_node] + p.second;
            if (nxt_dist < dist[p.first]) {
                dist[p.first] = nxt_dist;
                pq.push({ -nxt_dist, p.first });
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int e, u, vv, w, v1, v2;
    cin >> v >> e;
    graph.resize(v);
    dist = new int[v];
    while (e--) {
        cin >> u >> vv >> w;
        graph[u - 1].push_back({ vv - 1, w });
        graph[vv - 1].push_back({ u - 1, w });
    }
    cin >> v1 >> v2;
    dijkstra(0);
    int zerotov1 = dist[--v1];
    int zerotov2 = dist[--v2];
    dijkstra(v1);
    int v1toN = dist[v - 1];
    int v1tov2 = dist[v2];
    dijkstra(v2);
    int v2toN = dist[v - 1];
    
    int ret = min(zerotov1 + v2toN, zerotov2 + v1toN) + v1tov2;
    if (ret >= INF) cout << "-1";
    else cout << ret;
}