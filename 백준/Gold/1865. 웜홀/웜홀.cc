#include <iostream>
using namespace std;
#define INF 500'000'000

struct box {
	short a, b, c;
};

box graph[5200];
int dist[500];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int tc, i, n, m, w;
	cin >> tc;
	short s, e, t;
	while (tc--) {
		cin >> n >> m >> w;
		for (i = 0; i < 2 * m; i++) {
			cin >> s >> e >> t;
			graph[i] = { --s, --e, t };
			graph[++i] = { e, s, t };
		}
		for (; i < 2 * m + w; i++) {
			cin >> s >> e >> t;
			graph[i] = { --s, --e, (short)(-t)};
		}
		e = 2 * m + w; //간선 개수

		//벨만 포드
		for (i = 1; i < n; i++)
			dist[i] = INF;
		dist[0] = 0;
		for (i = 0; i < n - 1; i++) {
			for (int j = 0; j < e; j++) {
				box p = graph[j];
				if (dist[p.a] + p.c < dist[p.b])
					dist[p.b] = dist[p.a] + p.c;
			}
		}
		//음의 사이클 유무 확인
		bool check = false;
		for (int j = 0; j < e; j++) {
			box p = graph[j];
			if (dist[p.a] + p.c < dist[p.b]) {
				check = true; break;
			}	
		}
		if (check) cout << "YES\n";
		else cout << "NO\n";
	}
}