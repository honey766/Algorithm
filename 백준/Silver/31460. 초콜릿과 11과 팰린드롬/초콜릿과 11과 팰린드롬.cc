#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	//짝수면 11'11'11'11처럼 만든다(11 * 1010101)
	//홀수면 11'121'11처럼 만든다(11 * 101101)
	int tc, n;
	cin >> tc;
	while (tc--) {
		cin >> n;
		if (n % 2) {
			for (int i = 0; i < n / 2; i++) cout << '1';
			if (n % 4 == 1) cout << '0';
			else cout << '2';
			for (int i = 0; i < n / 2; i++) cout << '1';
		}
		else {
			for (int i = 0; i < n; i++) cout << '1';
		}
		cout << '\n';
	}
}