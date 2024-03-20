#include <iostream>
#include <cstring>
using namespace std;

int n, m;
char arr[50][50];
char visited[50][50];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

bool validPos(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < m;
}

int check(char kk) {
	if (kk % 2) return kk - 1;
	else return kk + 1;
}

bool dfs(char i, char j, char c, char kk) {
	for (int k = 0; k < 4; k++) {
		if (check(kk) == k) continue;
		int ni = i + dy[k];
		int nj = j + dx[k];
		if (validPos(ni, nj) && arr[ni][nj] == c) {
			if (visited[ni][nj] == c) //visited
				return true;
			else {
				visited[ni][nj] = c;
				if(dfs(ni, nj, c, k)) return true;
			}
		}
	}
	return false;
}

bool f(char c) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (arr[i][j] != c || visited[i][j] == c) continue;
			visited[i][j] = c;
			if (dfs(i, j, c, -1))
				return true;
		}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	string s;
	memset(visited, -1, 2500);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++)
			arr[i][j] = s[j] - 'A';
	}
	for(int i = 0; i < 26; i++)
		if (f(i)) {
			cout << "Yes";
			return 0;
		}
	cout << "No";
}