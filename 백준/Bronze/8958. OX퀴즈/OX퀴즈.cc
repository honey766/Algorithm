#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, cnt, sum;
	string s;
	cin >> n;
	while (n--) {
		cin >> s;
		cnt = sum = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'O')
				sum += (++cnt);
			else
				cnt = 0;
		}
		cout << sum << '\n';
	}
}