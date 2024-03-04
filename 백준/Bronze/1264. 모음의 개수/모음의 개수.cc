#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	string s;
	int cnt;
	while (true) {
		getline(cin, s);
		cnt = 0;
		if (s == "#")break;
		for (char c : s) {
			if (c >= 'a') c -= 'a' - 'A';
			if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') cnt++;
		}
		cout << cnt << '\n';
	}
}