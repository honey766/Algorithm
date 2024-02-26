#include <iostream>
using namespace std;

int main()
{
	int a;
	cout << "100\n";
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (i == 100 || j == 100 || i == j) a = 0;
			else a = 9999;
			cout << a << ' ';
		}
		cout << '\n';
	}
}
