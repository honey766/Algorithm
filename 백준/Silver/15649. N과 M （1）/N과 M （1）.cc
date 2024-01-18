#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;

void print(int n, int m, bool* visited) {
	int len = vec.size();
	if (m == 0) {
		for (int j = 0; j < len; j++)
			cout << vec[j] << ' ';
		cout << '\n'; return;
	}
	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		vec.push_back(i + 1);
		print(n, m - 1, visited);
		visited[i] = false;
		vec.erase(vec.begin() + len);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	bool* visited = new bool[n]();
	print(n, m, visited);
}