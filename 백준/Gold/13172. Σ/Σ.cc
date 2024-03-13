#include <iostream>
using namespace std;
#define N 1'000'000'007
#define ll long long

int pows(ll n) {
	ll b = N - 2, ret = 1;
	while (b) {
		if (b % 2)
			ret = (ret * n) % N;
		n = (n * n) % N;
		b /= 2;
	}
	return (int)ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int m; cin >> m;
	int sum = 0, n, s, tmp;
	while (m--) {
		cin >> n >> s;
		// (n / s) % N
		tmp = ((ll)s * pows(n)) % N;
		sum = (sum + tmp) % N;
	}
	cout << sum;
}