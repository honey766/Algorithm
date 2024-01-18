#include <iostream>
using namespace std;

int Min = 1000000000, n;
int** arr;
int* sel;

void cal() {
	int sn = n / 2, score1 = 0, score2 = 0;
	int k = 0, l;
	for (int i = 0; i < sn; i++)
		for (int j = 0; j < sn; j++)
			score1 += arr[sel[i]][sel[j]];
	for (int i = 0; i < n; i++) {
		if (k < sn && i == sel[k]) {
			k++; continue;
		}
		l = 0;
		for (int j = 0; j < n; j++) {
			if (l < sn && j == sel[l]) {
				l++; continue;
			}
			score2 += arr[i][j];
		}
	}
	score1 = (score1 > score2) ? (score1 - score2) : (score2 - score1);
	Min = score1 < Min ? score1 : Min;
}

void select(int cnt, int i0) {
	if (cnt == n / 2) {
		cal(); return;
	}
	for (int i = i0; i < n; i++) {
		sel[cnt] = i;
		select(cnt + 1, i + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int a;
	cin >> n;
	arr = new int* [n];
	sel = new int[n / 2];
	for (int i = 0; i < n; i++) arr[i] = new int[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> a; arr[i][j] = a;
		}
	select(0, 0);
	cout << Min;
}