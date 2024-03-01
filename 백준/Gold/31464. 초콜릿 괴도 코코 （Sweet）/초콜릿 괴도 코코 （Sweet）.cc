#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

char arr[40][40];
bool visited[40][40];
vector<pair<int, int>> vec;
int n;
int T1[4] = { -1, 1, 0, 0 };
int T2[4] = { 0, 0, -1, 1 };
bool check;
int cnt;

int parent[1600];
int Rank[1600];

int Find(int a) {
	if (a == parent[a]) return a;
	return parent[a] = Find(parent[a]);
}

bool Union(int a, int b) {
	int A = Find(a);
	int B = Find(b);

	if (A == B) return true;
	if (Rank[A] < Rank[B]) parent[A] = B;
	else if (Rank[A] > Rank[B]) parent[B] = A;
	else {
		parent[B] = A;
		Rank[A]++;
	}
	return false;
}

int f(int i, int j) {
	return n * i + j;
}

bool validPos(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < n;
}
bool good(int k, int prev) {
	return k == 0 && prev == 1 || k == 1 && prev == 0 || k == 2 && prev == 3 || k == 3 && prev == 2;
}

void dfs(int i, int j, int prev) {
	cnt++;
	for (int k = 0; k < 4; k++) {
		//바로 전에 이동한 곳이라면 패스
		if (good(k, prev)) continue;
		int ni = i + T1[k];
		int nj = j + T2[k];
		if (validPos(ni, nj) && arr[ni][nj] == '#') {
			if (Union(f(i, j), f(ni, nj))) { //이미 같은 집단이었다면 사이클임
				check = true;
				return;
			}
			else if (!visited[ni][nj]) {
				visited[ni][nj] = true;
				dfs(ni, nj, k);
			}
		}
	}
}
void visit(int i, int j) {
	visited[i][j] = true;
	dfs(i, j, -1);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	vector<pair<int, int>> ret;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			arr[i][j] = s[j];
			if (s[j] == '#') vec.push_back({ i, j }); //떼어낼 수 있는 초콜릿 목록
		}
	}

	for (int i = 0; i < vec.size(); i++) {
		cnt = 0;
		check = false;
		memset(visited, 0, 1600);
		for (int j = 0; j < n * n; j++)
			parent[j] = j;
		int ni = vec[i].first, nj = vec[i].second;
		arr[ni][nj] = '.';
		//한 개를 제거했을 때 사이클이 있나 확인한다. 사이클이 없어야 문제의 조건을 만족한다
		if (i == 0) visit(vec[1].first, vec[1].second);
		else visit(vec[0].first, vec[0].second);
		if (!check && (cnt == vec.size() - 1)) ret.push_back({ ni, nj });
		arr[ni][nj] = '#';
	}
	cout << ret.size() << '\n';
	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i].first + 1 << ' ' << ret[i].second + 1;
		cout << '\n';
	}
}