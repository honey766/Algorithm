#include <iostream>
using namespace std;

int half[12];
//3x2^n에서 i번째 줄을 출력
void f(int n, int i) {
	if (n == 0) {
		if (i == 0) cout << '*';
		else if (i == 1) cout << "* *";
		else cout << "*****";
		return;
	}
	if (i < half[n]) {
		f(n - 1, i); return;
	}

	i -= half[n];
	f(n - 1, i);
	for (int j = 0; j < (2 * half[n] - 1) - 2 * i; j++)
		cout << ' ';
	f(n - 1, i);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, target;
	cin >> target;
	half[1] = 3;
	for (int i = 2; i <= 11; i++)
		half[i] = half[i - 1] * 2;
	for (int i = 1; i <= 11; i++)
		if (target == half[i]) n = i;

	for (int i = 0; i < target; i++) {
		for (int j = 0; j < target - i - 1; j++) cout << ' ';
		f(n - 1, i); 
		for (int j = 0; j < target - i - 1; j++) cout << ' ';
		cout << '\n';
	}
}