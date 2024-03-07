#include <iostream>
#include <vector>
using namespace std;
#define pr pair<int, int>

vector<vector<int>> graph;
//n이 루트인 서브트리에서, { 자기가 아답터일 때 최솟값, 아닐 때 최솟값 }
pr dfs(int n, int p) {
	int on = 1, off = 0;
	for (int a : graph[n]) {
		if (a == p) continue;
		pr p = dfs(a, n);
		on += min(p.first, p.second);
		off += p.first;
	}
	return { on, off };
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int a, b, n;
	cin >> n;
	graph.resize(n);
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		graph[--a].push_back(--b);
		graph[b].push_back(a);
	}
	pr p = dfs(0, -1);
	cout << min(p.first, p.second);
}