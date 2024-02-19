#include <iostream>
#include <cstring>
using namespace std;

int m, n;
short arr[500][500];
int dp[500][500]; //dp[i][j] : (i,j)에서 (m-1,n-1)까지 가는 경우의 수
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1 ,1 }; //상하좌우

bool validPos(int i, int j) {
	return 0 <= i && i < m && 0 <= j && j < n;
}

int dfs(int i, int j) {
	if (dp[i][j] != -1) return dp[i][j];
	if (i == m - 1 && j == n - 1) return 1;
	
	int ni, nj, cnt = 0;

	for (int k = 0; k < 4; k++) {
		ni = i + dx[k];
		nj = j + dy[k];
		if (validPos(ni, nj) && arr[i][j] > arr[ni][nj])
			cnt += dfs(ni, nj);
	}

	return dp[i][j] = cnt;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> m >> n;
	memset(dp, -1, 1000000);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	cout << dfs(0, 0);
}