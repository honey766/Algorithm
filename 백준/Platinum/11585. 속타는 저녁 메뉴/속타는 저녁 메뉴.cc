#include <iostream>
#include <string>
using namespace std;

int pi[1'000'000];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n;
	string s;
	cin >> n;
	cin.ignore();
	getline(cin, s);
	int j = 0;
	for (int i = 1; i < n; i++) {
		while (j > 0 && s[2 * j] != s[2 * i])
			j = pi[j - 1];
		if (s[2 * j] == s[2 *i])
			pi[i] = ++j;
		else
			pi[i] = 0;
	}
	//abcabcabc는 pi[8]==6이며, (9-6)개의 문자열이 9/3번 반복된다.
	
	getline(cin, s);
	int rep = n - pi[n - 1];
	if (n % rep == 0) cout << "1/" << rep;
	else cout << "1/" << n;
}