#include <iostream>
#include <cstring>
using namespace std;

char arr[100][100];
bool visit[100][100];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = { 0, 0, -1, 1 };
int n;

bool validPos(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < n;
}

void dfs(int i, int j, int height) {
	for (int k = 0; k < 4; k++) {
		int ni = i + dy[k];
		int nj = j + dx[k];
		if (validPos(ni, nj) && !visit[ni][nj] && arr[ni][nj] > height) {
			visit[ni][nj] = true;
			dfs(ni, nj, height);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int a, cnt, MaxH = -1, Max = -1;
	cin >> n;
	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> a;
			arr[i][j] = a;
			MaxH = max(MaxH, a);
		}

	for (int height = 0; height < MaxH; height++) {
		cnt = 0;
		memset(visit, 0, 10000);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visit[i][j] || arr[i][j] <= height) continue;
				cnt++;
				visit[i][j] = true;
				dfs(i, j, height);
			}
		}
		Max = max(Max, cnt);
	}
	cout << Max;
}