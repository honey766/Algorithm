#include <iostream>
using namespace std;
#define ll long long

int n, k;
string arr[15];
int arrRem[15];
int pows[750];
ll dp[1 << 15][100]; // dp[status][현재 나머지]

ll f(int status, int len, int rem) {
	if (status == (1 << n) - 1)
		return (rem == 0);

	if (dp[status][rem] != -1) return dp[status][rem];

	ll cnt = 0;
	for (int i = 0; i < n; i++) {
		if (status & (1 << i)) continue;
		cnt += f(status | (1 << i), len - arr[i].size(), (rem + arrRem[i] * pows[len - arr[i].size()]) % k);
	}
	return dp[status][rem] = cnt;
}

void calArr(int a) {
	string& s = arr[a];
	int rem = 0;
	for (int i = 0; i < s.size(); i++)
		rem = (rem + (s[i] - '0') * pows[s.size() - i - 1]) % k;
	arrRem[a] = rem;
}

ll fact(int n) {
	ll ret = 1;
	for (int i = 2; i <= n; i++) ret *= i;
	return ret;
}

ll gcd(ll a, ll b) {
	ll tmp;
	while (b) {
		tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int totalLen = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		totalLen += arr[i].size();
	}
	cin >> k;
	pows[0] = 1;
	for (int i = 1; i < totalLen; i++)
		pows[i] = (pows[i - 1] * 10) % k;
	for (int i = 0; i < n; i++)
		calArr(i);
	for (int i = 0; i < (1 << n); i++)
		for (int j = 0; j < k; j++)
			dp[i][j] = -1;

	ll up = f(0, totalLen, 0);
	ll down = fact(n);
	ll gcd_ = gcd(down, up);
	cout << (up / gcd_) << '/' << (down / gcd_);
}