#include <iostream>
#include <vector>
using namespace std;

vector<int>* graph;
bool* coupled; //짝지어졌으면 true
int n, cnt, maxCnt;

void dfs(int r) {
	if (n <= r) {
		maxCnt = max(maxCnt, cnt);
		return;
	}
	if (!coupled[r]) {
		coupled[r] = true;
		for (int v : graph[r])
			if (!coupled[v]) {
				coupled[v] = true;
				cnt += 2;
				dfs(r + 1);
				coupled[v] = false;
				cnt -= 2;
			}
		coupled[r] = false;
	}
	dfs(r + 1);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int m, a1, a2;
	cin >> n >> m;
	graph = new vector<int>[n];
	coupled = new bool[n]();
	while (m--) {
		cin >> a1 >> a2;
		graph[--a1].push_back(--a2);
		graph[a2].push_back(a1);
	}
	dfs(0);
	cout << (maxCnt == n ? maxCnt : maxCnt + 1);
}