#include <iostream>
using namespace std;
#define N 1'000'000'007
#define ll long long

int fact[4'000'001];

// (a^b) % N
ll pows(ll a, ll b) {
	ll ret = 1;
	while (b) {
		if (b % 2)
			ret = (ret * a) % N;
		a = (a * a) % N;
		b /= 2;
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	fact[0] = 1;
	for (int i = 1; i <= 4'000'000; i++)
		fact[i] = ((ll)fact[i - 1] * i) % N;

	int tc, n, k;
	long long a1, a2;
	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		a1 = fact[n];
		a2 = ((ll)fact[k] * fact[n - k]) % N;
		//구하려는 것은 (a1 / a2) % N
		// == (a1 * (a2 ^ (N-2))) % N

		a2 = pows(a2, N - 2);
		cout << (a1 * a2) % N << '\n';
	}
}