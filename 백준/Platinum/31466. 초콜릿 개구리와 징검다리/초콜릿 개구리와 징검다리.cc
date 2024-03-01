#include <iostream>
using namespace std;

int n, sn;

//a에서 b칸 이동
void jump(int a, int b) {
	cout << a << ' ' << a + b << '\n';
}

void even() {
	int a;
	cout << (sn * (sn + 1) / 2) * 5 + (sn + 1) * 5 << '\n';

	for (int i = 0; i < sn; i++) {
		a = 0;
		for (int j = 0; j < sn - i; j++) {
			jump(a, 1);
			jump(a, 2);
			jump(a + 1, 1);
			a += 2;
		}
	}

	for (int i = 1; i < n; i += 2) {
		a = i;
		jump(a - 1, 1);
		for (; a < n - 2; a += 2) {
			jump(a, 2);
		}
		jump(a, 1);

		a = i;
		jump(a - 1, 1);
		for (; a < n - 2; a += 2) {
			jump(a, 2);
		}
		jump(a, 2);
		jump(a + 1, 1);
	}
}

void odd1() {
	cout << "8\n";
	jump(0, 1);
	jump(0, 2);
	jump(2, 1);
	jump(0, 2);

	jump(2, 2);
	jump(3, 1);
	jump(1, 2);
	jump(3, 1);
}

void odd2() {
	cout << "19\n";
	jump(0, 2);
	jump(0, 1);
	jump(1, 2);
	jump(2, 1);
	jump(0, 1);

	jump(0, 2);
	jump(2, 2);
	jump(4, 1);
	jump(0, 2);
	jump(2, 2);

	jump(4, 2);
	jump(5, 1);
	jump(1, 1);
	jump(2, 2);
	jump(4, 2);

	jump(3, 1);
	jump(3, 2);
	jump(5, 1);
	jump(4, 2);
}

void odd3() {
	cout << "1\n";
	jump(0, 2);
}

void odd() {
	if (n == 1) {
		odd3();
		return;
	}
	else if (n == 3) {
		odd1();
		return;
	}
	else if (n == 5) {
		odd2();
		return;
	}
	cout << 9 * sn + 3 * sn * (sn - 1) / 2 + sn * (sn + 1) + 11 << '\n';
	int a = 1;
	jump(a - 1, 1);
	for (int i = 0; i < sn - 1; i++) {
		jump(a, 2);
		a += 2;
	}
	a = 1;
	jump(a - 1, 1);
	for (int i = 0; i < sn - 2; i++) {
		jump(a, 2);
		a += 2;
	}
	a = 0;
	for (int i = 0; i < sn; i++) {
		jump(a, 2);
		a += 2;
	}
	a -= 3;
	jump(a, 1);
	jump(a + 1, 2);
	jump(a + 2, 1);


	for (int i = 0; i < sn - 1; i++) {
		a = 0;
		for (int j = 0; j < sn - 1 - i; j++) {
			jump(a, 1);
			jump(a, 2);
			jump(a + 1, 1);
			a += 2;
		}
	}

	for (int j = 0; j < sn; j++) {
		a = 1 + 2 * j;
		jump(a - 1, 1);
		for (int i = 0; i < sn - j; i++) {
			jump(a, 2);
			a += 2;
		}
		jump(a, 2);
		a = 1 + 2 * j;
		jump(a - 1, 1);
		for (int i = 0; i < sn - j; i++) {
			jump(a, 2);
			a += 2;
		}
		jump(a, 1);
		jump(a + 1, 2);
		jump(a + 2, 1);
	}

	a = n - 3;
	jump(a, 1);
	jump(a, 2);
	jump(a + 1, 1);
	jump(a, 1);
	jump(a + 1, 2);
	jump(a + 3, 1);
	jump(a + 2, 1);
	jump(a + 2, 2);
	jump(a + 3, 1);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	//8이라면 다음과 같이 만든다
	// 5 3 1
	// 6 4 2
	//OOOOOOOO
	//9라면 다음과 같이 만든다
	//     1
	// 7 4 2
	// 6 5 3
	//OOOOOOOOO

	cin >> n;
	sn = n / 2 - 1;

	if (n % 2) odd();
	else even();
}