#include <iostream>
using namespace std;

int n, m;
int arr[7];

void print(int cnt) {
	if (cnt == m) {
		for (int j = 0; j < m; j++)
			cout << arr[j] << ' ';
		cout << '\n'; return;
	}
	for (int i = 0; i < n; i++) {
		arr[cnt] = i + 1;
		print(cnt + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> n >> m;
	print(0);
}