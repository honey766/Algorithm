#include <iostream>
using namespace std;

int pi[1'000'000];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	string s;
	while (cin >> s) {
		if (s == ".") break;
		int j = 0;
		for (int i = 1; i < s.size(); i++) {
			while (j > 0 && s[j] != s[i])
				j = pi[j - 1];
			if (s[j] == s[i])
				pi[i] = ++j;
			else
				pi[i] = 0;
		}
		//abcabcabc는 pi[8]==6이며, (9-6)개의 문자열이 반복된다.
		int sz = s.size();
		int n = sz - pi[sz - 1];
		if (sz % n == 0) cout << sz / n << '\n';
		else cout << "1\n";
	}
}