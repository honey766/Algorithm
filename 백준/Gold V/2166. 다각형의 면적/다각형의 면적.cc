#include <iostream>
#include <vector>
using namespace std;
#define pr pair<double, double>

double cal(pr& o, pr& prev, pr& cur) {
	return 0.5 * ((prev.first - o.first) * (cur.second - prev.second) - (cur.first - prev.first) * (prev.second - o.second));
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cout << fixed;
	cout.precision(1);

	pr o, prev, cur;
	double area = 0;
	int n;
	cin >> n >> o.first >> o.second >> cur.first >> cur.second;
	for (int i = 0; i < n - 2; ++i) {
		prev = cur;
		cin >> cur.first >> cur.second;
		area += cal(o, prev, cur);
	}
	area = area > 0 ? area : -1 * area;
	cout << area;
}