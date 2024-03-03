#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t, h, w, n;
	cin >> t;
	while (t--) {
		cin >> h >> w >> n;
		cout << (--n) % h + 1;
		if ((w = n / h + 1) < 10) cout << 0;
		cout << w << '\n';
	}
}