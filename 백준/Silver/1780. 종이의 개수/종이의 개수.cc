#include <iostream>
using namespace std;

char arr[2187][2187];
int mi, zero, pl;

// (a,b) 시작점, n*n 크기
void f(int a, int b, int n) {
	bool allMi, allZe, allPl;
	allMi = allZe = allPl = true;
	for (int i = a; i < a + n; i++) {
		for (int j = b; j < b + n; j++) {
			if (arr[i][j] != -1) allMi = false;
			if (arr[i][j] != 0) allZe = false;
			if (arr[i][j] != 1) allPl = false;
		}
		if (!allMi && !allZe && !allPl) break;
	}
	if (allMi) mi++;
	else if (allZe) zero++;
	else if (allPl) pl++;
	else {
		int sn = n / 3;
		for (int i = a; i < a + n; i += sn)
			for (int j = b; j < b + n; j += sn)
				f(i, j, sn);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, a;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> a;
			arr[i][j] = a;
		}
	f(0, 0, n);
	cout << mi << '\n' << zero << '\n' << pl;
}