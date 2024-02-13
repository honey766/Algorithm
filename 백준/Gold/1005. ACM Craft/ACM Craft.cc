#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
#define pr pair<int, short>

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int tc, n, k, x, y, w, t;
    int d[1000];
    short indegree[1000];
    cin >> tc;
    while (tc--) {
        cin >> n >> k;
        vector<vector<short>> graph(n, vector<short>());
        priority_queue<pr, vector<pr>, greater<pr>> pq; // {짓기까지 걸리는 시간, 노드 번호 i}
        memset(indegree, 0, 2000);
        for (int i = 0; i < n; ++i)
            cin >> d[i];
        while (k--) {
            cin >> x >> y;
            graph[x - 1].push_back(y - 1);
            ++indegree[y - 1];
        }
        cin >> w;
        --w;

        //DAG
        for (int i = 0; i < n; ++i)
            if (!indegree[i]) pq.push({ d[i], i });
        for (int i = 0; i < n; ++i) {
            t = pq.top().first;
            int idx = pq.top().second;
            if (idx == w) break;
            pq.pop();
            for (short b : graph[idx])
                if (--indegree[b] == 0) pq.push({ t + d[b], b });
        }
        cout << t << '\n';
    }
}