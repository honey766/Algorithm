#include <iostream>
#include <cmath>
using namespace std;

void line(int n) {
	if (n <= 0) {
		cout << '-'; return;
	}
	int p = pow(3, n - 1);
	line(n - 1);
	for (int i = 0; i < p; i++) cout << ' ';
	line(n - 1);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int n;
	while (cin >> n) {
		line(n); cout << '\n';
	}
}