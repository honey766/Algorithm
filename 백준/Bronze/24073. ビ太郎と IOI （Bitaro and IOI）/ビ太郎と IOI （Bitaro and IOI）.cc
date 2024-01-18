#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, check = 0;
	string s;
	char c[3] = { 'I', 'O', 'I' };
	cin >> n >> s;
	while (--n >= 0) {
		if (s[n] == c[check]) {
			check++;
			if (check == 3) break;
		}
	}
	if (check == 3) cout << "Yes";
	else cout << "No";
}