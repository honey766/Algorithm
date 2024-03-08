#include <iostream>
using namespace std;

int main() {
	int n, f, a;
	cin >> n >> f;
	n = (n / 100) * 100;
	for (a = 0; (n + a) % f; a++);
	if (a < 10) cout << 0;
	cout << a;
}