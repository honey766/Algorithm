#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int tc, number;
	bool rev, numCome;
	string s;
	cin >> tc;
	while (tc--) {
		cin >> s;
		numCome = rev = false;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != '!') {
				numCome = true;
				number = s[i] - '0';
			}
			else if (numCome) {
				number = 1;
			}
			else {
				rev = !rev;
			}
		}
		//rev가 true라면 숫자 반전
		if (rev) number = 1 - number;
		cout << number << '\n';
	}
}