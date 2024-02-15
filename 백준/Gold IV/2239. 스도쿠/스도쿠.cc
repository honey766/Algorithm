#include <iostream>
#include <vector>
using namespace std;

struct XY {
	int x;
	int y;
};

bool horizon[9][10], vertical[9][10], square[9][10];
//horizon : 각 수평선에서 1~9가 들어있는지
//vertical : 각 수직선
//square : 각 3x3 사각형
int arr[9][9];
bool complete;
vector<XY> vec;

void sudoku(int cnt)
{
	if (cnt == vec.size()) {
		complete = true; return;
	}
	int i = vec[cnt].x, j = vec[cnt].y;
	int si = (i / 3) * 3 + j / 3;
	for (int k = 1; k <= 9; k++) {
		if (horizon[i][k] || vertical[j][k] || square[si][k]) continue;
		horizon[i][k] = vertical[j][k] = square[si][k] = true;
		arr[i][j] = k;
		sudoku(cnt + 1);
		if (complete) return;
		horizon[i][k] = vertical[j][k] = square[si][k] = false;
		arr[i][j] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	string s;
	int a, i, j;
	complete = false;
	for (i = 0; i < 9; i++)
		for (j = 0; j < 9; j++)
			horizon[i][j] = vertical[i][j] = square[i][j] = false;
	for (i = 0; i < 9; i++) {
		cin >> s;
		for (j = 0; j < 9; j++) {
			a = s[j] - '0';
			arr[i][j] = a;
			if (a == 0)
				vec.push_back({ i, j });
			else {
				horizon[i][a] = true; vertical[j][a] = true;
				square[(i / 3) * 3 + j / 3][a] = true;
			}
		}
	}
	sudoku(0);
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}
}