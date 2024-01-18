#include <iostream>
using namespace std;

void hanoi(int n, int a, int b, int c) {
	if (n < 1) return;
	hanoi(n - 1, a, c, b);
	cout << a << ' ' << c << '\n';
	hanoi(n - 1, b, a, c);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int n;
	long long int p = 1;
	cin >> n;
	for (int i = 0; i < n; i++) p *= 2;
	cout << p - 1 << '\n';
	hanoi(n, 1, 2, 3);
}