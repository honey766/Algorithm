#include <iostream>
using namespace std;

void fib(int n, int& n1) {
	if (n == 1 or n == 2) {
		n1++; return;
	}
	else {
		fib(n - 1, n1); fib(n - 2, n1); return;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int n, n1 = 0;
	cin >> n;
	fib(n, n1);
	cout << n1 << ' ' << n - 2;
}