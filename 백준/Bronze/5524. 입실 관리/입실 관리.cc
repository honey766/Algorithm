#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	string s;
	while (n--) {
		cin >> s;
		for (int i = 0; i < s.size(); i++)
			if ('A' <= s[i] && s[i] <= 'Z')
				s[i] += 'a' - 'A';
		cout << s << '\n';
	}
}