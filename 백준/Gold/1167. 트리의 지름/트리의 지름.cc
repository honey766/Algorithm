#include <iostream>
#include <vector>
using namespace std;
#define pis pair<int, short>
#define pii pair<int, int>

int n;
vector<vector<pis>> graph;

// { n을 루트로 했을 때 리프노드까지 최대 길이, 가장 긴 2개의 길이 합(서브트리 포함) }
pii dfs(int n, int p) {
	int t, first = 0, second = 0, Max = -1;
	for (pis pr : graph[n]) {
		if (pr.first == p) continue;
		pii tmp = dfs(pr.first, n);
		Max = max(Max, tmp.second);

		t = tmp.first + pr.second;
		if (first <= t) {
			second = first;
			first = t;
		}
		else if (second < t)
			second = t;
	}
	return { first, max(first + second, Max) };
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	int a, b, c;
	graph.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a;
		a--;
		while (true) {
			cin >> b;
			if (--b == -2) break;
			cin >> c;
			graph[a].push_back({ b, c });
		}
	}
	cout << dfs(0, -1).second;
}