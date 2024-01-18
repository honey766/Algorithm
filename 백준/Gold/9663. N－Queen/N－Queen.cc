#include <iostream>
using namespace std;

int n, totalcnt;
int** visited;

void visit(int cnt, int j, bool isVisiting) {
	int t = (isVisiting ? 1 : -1);
	//방문하면 1씩 늘리고, 방문 끝내면 1씩 줄임
	for (int i = 0; i < n; i++) //수평
		visited[i][j] += t;
	for (int i = 0; i < n; i++) //수직
		visited[cnt][i] += t;
	int min1 = min(cnt, j), max1 = max(cnt, j);
	int min2 = min(cnt, n - j - 1), max2 = max(cnt, n - j - 1);
	for (int i = -min1; i < n - max1; i++) //왼쪽위~오른아래
		visited[cnt + i][j + i] += t;
	for (int i = -min2; i < n - max2; i++) //오른쪽위~왼아래
		visited[cnt + i][j - i] += t;
	visited[cnt][j] -= 3 * t;
}

void queen(int cnt) {
	if (cnt == n) {
		totalcnt++; return;
	}
	for (int i = 0; i < n; i++) {
		if (visited[cnt][i] > 0) continue;
		visit(cnt, i, true);
		queen(cnt + 1);
		visit(cnt, i, false);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	visited = new int* [n];
	for (int i = 0; i < n; i++) visited[i] = new int[n]();
	totalcnt = 0;

	queen(0);
	cout << totalcnt;
}