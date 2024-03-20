#include <iostream>
#include <set>
using namespace std;

int f(int i, int j) {
	return (long long)(i + j - 1) * (i + j - 2) / 2 + j;
}

bool valid(int i, int j) {
	return 0 < i && 0 < j;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	set<int> st;
	st.insert(1);
	int i = 1, j = 1, k;
	int Min, ni, nj, val;
	cin >> k;
	for (int a = 0; a < k; a++) {
		Min = INT32_MAX;
		ni = -1;
		for (int b = -2; b <= 2; b += 4) {
			for (int c = -1; c <= 1; c += 2) {
				val = f(i + b, j + c);
				if (valid(i + b, j + c) && !st.count(val) && val < Min) {
					Min = val;
					ni = i + b;
					nj = j + c;
				}
				val = f(i + c, j + b);
				if (valid(i + c, j + b) && !st.count(val) && val < Min) {
					Min = val;
					ni = i + c;
					nj = j + b;
				}
			}
		}
		if (ni == -1) break;
		st.insert(f(ni, nj));
		i = ni;
		j = nj;
	}
	cout << f(i, j);
}