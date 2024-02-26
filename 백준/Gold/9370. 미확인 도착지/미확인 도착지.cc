#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 1'000'000'000
#define pr pair<int, int>

vector<vector<pr>> graph;
int dist[2000];
int dest[100];
int distT[100][3]; //distT[i][0~2] : 각각 s, g, h에서 출발해서 dest[i]로 도착하는 최단거리
int n, sTog, sToh, gToh;

void dijkstra(int k) {
    for (int i = 0; i < n; i++)
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

    int tc, m, t, s, g, h, a, b, d, x;
    cin >> tc;
    while (tc--) {
        cin >> n >> m >> t >> s >> g >> h;
        s--; g--; h--;
        graph.clear();
        graph.resize(n);
        while (m--) {
            cin >> a >> b >> d;
            graph[a - 1].push_back({ b - 1, d });
            graph[b - 1].push_back({ a - 1, d });
        }
        for (int i = 0; i < t; i++) {
            cin >> x;
            dest[i] = x - 1;
        }
        sort(dest, dest + t);

        dijkstra(s);
        for (int i = 0; i < t; i++) distT[i][0] = dist[dest[i]];
        sTog = dist[g]; sToh = dist[h];

        dijkstra(g);
        for (int i = 0; i < t; i++) distT[i][1] = dist[dest[i]];
        gToh = dist[h];

        dijkstra(h);
        for (int i = 0; i < t; i++) distT[i][2] = dist[dest[i]];

        //최단거리가 g, h를 지나는지 검사, 즉 s~dest[i] == s~g~h~dest[i] 또는 s~h~g~dest[i]
        for (int i = 0; i < t; i++)
            if (distT[i][0] == min(sTog + distT[i][2], sToh + distT[i][1]) + gToh)
                cout << dest[i] + 1 << ' ';
        cout << '\n';
    }
}