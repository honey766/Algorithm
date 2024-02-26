#include <iostream>
using namespace std;
#define INF 1'000'000'000

struct box {
    short a, b, c;
};
box graph[6000];
int n, m;
int dist[500];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    short a, b, c;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        graph[i] = { --a, --b, c };
    }

    for (int i = 1; i < n; i++)
        dist[i] = INF;
    dist[0] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            box p = graph[j];
            if (dist[p.a] == INF) continue;
            if (dist[p.a] + p.c < dist[p.b])
                dist[p.b] = dist[p.a] + p.c;
            if (dist[p.b] < -INF) {
                cout << "-1";
                return 0;
            }
        }
    }
    //음의 사이클 유무 확인
    for (int j = 0; j < m; j++) {
        box p = graph[j];
        if (dist[p.a] == INF) continue;
        if (dist[p.a] + p.c < dist[p.b]) {
            cout << "-1";
            return 0;
        } 
    }

    for (int i = 1; i < n; i++) {
        if (dist[i] == INF) cout << "-1\n";
        else cout << dist[i] << '\n';
    }
}