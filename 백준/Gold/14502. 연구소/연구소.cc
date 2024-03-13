#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct Cor {
	char x, y;
};

int n, m, cnt;
char arr[8][8];
bool visited[8][8];
vector<Cor> virusPos;
vector<Cor> voidPos;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

bool validPos(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < m;
}

void dfs(int i, int j) {	
	cnt++;
	for (int k = 0; k < 4; k++) {
		int ni = i + dy[k];
		int nj = j + dx[k];
		if (!visited[ni][nj] && validPos(ni, nj) && arr[ni][nj] != '1') {
			visited[ni][nj] = true;
			dfs(ni, nj);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int voidCnt, Max = 0;
	cin >> n >> m;
	for (char i = 0; i < n; i++)
		for (char j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '0') voidPos.push_back(Cor{ i, j });
			else if(arr[i][j] == '2') virusPos.push_back(Cor{ i, j });
		}
	voidCnt = voidPos.size() - 3; //벽 3개 제외
	for (int i = 0; i < voidPos.size(); i++) {
		arr[voidPos[i].x][voidPos[i].y] = '1';
		for (int j = i + 1; j < voidPos.size(); j++) {
			arr[voidPos[j].x][voidPos[j].y] = '1';
			for (int k = j + 1; k < voidPos.size(); k++) {
				arr[voidPos[k].x][voidPos[k].y] = '1';
				memset(visited, 0, 64);
				cnt = 0;
				for (int ii = 0; ii < virusPos.size(); ii++) {
					if (!visited[virusPos[ii].x][virusPos[ii].y]) {
						visited[virusPos[ii].x][virusPos[ii].y] = true;
						dfs(virusPos[ii].x, virusPos[ii].y);
					}
				}
				Max = max(Max, (int)(voidCnt - (cnt - virusPos.size())));
				arr[voidPos[k].x][voidPos[k].y] = '0';
			}
			arr[voidPos[j].x][voidPos[j].y] = '0';
		}
		arr[voidPos[i].x][voidPos[i].y] = '0';
	}
	cout << Max;
}