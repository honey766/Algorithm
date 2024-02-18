#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool valid;
vector<vector<int>> graph;
char visit[20000];

void dfs(int n, int color) {
	visit[n] = color;
	for (int a : graph[n]) {
		if (visit[a] == color) {
			valid = false;
			return;
		}

		if (!visit[a])
			dfs(a, -color);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t, v, e, a, b;
	cin >> t;
	while (t--) {
		cin >> v >> e;
		memset(visit, 0, v);
		graph.resize(v);
		for (int i = 0; i < v; i++)
			graph[i].clear();
		while (e--) {
			cin >> a >> b;
			graph[a - 1].push_back(b - 1);
			graph[b - 1].push_back(a - 1);
		}
		valid = true;
		for (int i = 0; i < v; i++) {
			if (!visit[i]) dfs(i, 1);
			if (!valid) break;
		}
		if (valid) cout << "YES\n";
		else cout << "NO\n";
	}
}