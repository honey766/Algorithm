#include <iostream>
#include <algorithm>
using namespace std;
#define pr pair<int, int>
#define INF 2'000'000'000

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, sum = 0;
	cin >> n;
	pr* line = new pr[n];
	for (int i = 0; i < n; ++i)
		cin >> line[i].first >> line[i].second;
	sort(line, line + n);

	int l = -INF, r = -INF;
	for (int i = 0; i < n; ++i) {
		if (r < line[i].first) {
			sum += r - l;
			l = line[i].first;
			r = line[i].second;
		}
		else r = max(r, line[i].second);
	}
	sum += r - l;
	cout << sum;
}