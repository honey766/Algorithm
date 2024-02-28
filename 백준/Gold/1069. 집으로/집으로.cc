#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cout << fixed;
	cout.precision(16);
	int x, y, d, t;
	cin >> x >> y >> d >> t;
	double Min, dist = sqrt(x * x + y * y);

	int n = (int)(dist / d);
	n += (n == 0);
	Min = min(min(dist, n * t + abs(dist - d * n)), (1.0 + n) * t);
	cout << Min;
}