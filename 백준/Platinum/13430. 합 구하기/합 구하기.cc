#include <iostream>
using namespace std;
#define N 1'000'000'007
#define ll long long

int pows(ll a) {
	ll b = N - 2, ret = 1;
	while (b) {
		if (b % 2)
			ret = (ret * a) % N;
		a = (a * a) % N;
		b /= 2;
	}
	return (int)ret;
}

// S(0,n) = nC1, S(k,1) = (k+1)C(k+1)
// S(k,n) = S(k,n-1) + S(k-1,n)
// S(k,n) = (k+n)C(k+1)
// (n+k)C(k+1) = (n+k-1)C(k+1) + (n+k-1)C(k)  
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int k, n;
	cin >> k >> n;
	ll nPk, kPo; //n+k, k+1
	nPk = kPo = 1;
	for (int i = 0; i < k + 1; i++) {
		nPk = (nPk * (n + k - i)) % N;
		kPo = (kPo * (i + 1)) % N;
	}

	// (nPk / kPo) % N == (nPk * kPo^(N-2)) % N
	cout << (nPk * pows(kPo)) % N;
}