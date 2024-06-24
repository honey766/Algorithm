#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, x, y, a, dist, count; 
	bool board[100][100];
	cin >> n;
	while (n--) {
		cin >> x >> y;
		for(int i = 0; i < x; i++)
			for (int j = 0; j < y; j++) 
				cin >> board[x - 1 - i][j];
		dist = 0;
		for (int j = 0; j < y; j++) {
			count = 0; //각 열마다 맨 아래에 몇 개가 쌓였나
			for (int i = 0; i < x; i++) {
				if (!board[i][j]) continue;
				dist += i - count;
				count++;
			}
		}
		cout << dist << '\n';
	}
}