#include <iostream>
#include <vector>
using namespace std;
#define pii pair<int, int>

vector<vector<pii>> graph;

int maxDist, maxNode;
void dfs(int n, int p, int dist) {
	if (dist > maxDist) {
		maxDist = dist;
		maxNode = n;
	}
	for (pii pr : graph[n]) {
		if (pr.first == p) continue;
		dfs(pr.first, n, dist + pr.second);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, a, b, c;
	cin >> n;
	graph.resize(n);
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> c;
		graph[--a].push_back({ --b, c });
		graph[b].push_back({ a, c });
	}
	maxDist = 0;
	dfs(0, -1, 0);
	maxDist = 0;
	dfs(maxNode, -1, 0);
	cout << maxDist;
}