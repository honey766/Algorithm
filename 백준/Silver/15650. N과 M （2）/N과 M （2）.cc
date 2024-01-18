#include <iostream>
#include <vector>
using namespace std;

int n, m;
int arr[9];
bool visited[9];

void print(int cnt) {
	if (cnt > m) {
		for (int j = 1; j <= m; j++)
			cout << arr[j] << ' ';
		cout << '\n'; return;
	}
	int i = (cnt == 0 ? 1 : arr[cnt - 1] + 1);
	for (; i <= n; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		arr[cnt] = i;
		print(cnt + 1);
		visited[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> n >> m;
	for (int i = 0; i < 9; i++) visited[i] = false;
	print(1);
}