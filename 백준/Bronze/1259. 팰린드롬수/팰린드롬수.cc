#include <iostream>
using namespace std;

bool pal(string s) {
	int n = s.size();
	for (int i = 0; i < n / 2; i++)
		if (s[i] != s[n - 1 - i]) return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	string s;
	while (true) {
		cin >> s;
		if (s == "0") return 0;
		if (pal(s)) cout << "yes\n";
		else cout << "no\n";
	}
}