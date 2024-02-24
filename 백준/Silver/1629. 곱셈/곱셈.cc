#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	long long a, b, c, ret = 1;
	cin >> a >> b >> c;
	while (b) {
		if (b % 2)
			ret = (ret * a) % c;
		a = (a * a) % c;
		b /= 2;
	}
	cout << ret;
}