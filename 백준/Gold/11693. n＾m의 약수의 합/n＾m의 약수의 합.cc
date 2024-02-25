#include <iostream>
#include <vector>
using namespace std;
#define N 1'000'000'007
#define ll long long
#define pr pair<int, ll>

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

bool table[32000]; //대략 루트(10억)

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<pr> vec;
	for (int i = 2; i * i <= n; i++) {
		if (table[i]) continue;
		for (int j = i; j < 32000; j += i)
			table[j] = true;

		if (n % i == 0) {
			pr p = { i, 0 }; //i^0
			while (n % i == 0) {
				p.second++;
				n /= i;
			}
			p.second *= m; //지수 m배
			vec.push_back(p);
		}
	}
	if (n != 1) //현재의 소수 i에서, n은 i보다 큰 소수의 곱이며 i^i 이하이므로 n은 어떤 한 소수이다
		vec.push_back({ n, m });
	//n^m 소인수분해 완료

	//약수의 합 공식, 등비수열 합 이용
	ll ret = 1;
	for (int i = 0; i < vec.size(); i++) {
		ll a = vec[i].first;
		ll b = vec[i].second; //a^b
		//1 + ... + a^b = (a^(b+1) - 1) / (a-1)  (mod N)
		//		  = (a^(b+1) - 1) * (a-1)^(N-2)  (mod N)
		b = (pows(a, b + 1) + (N - 1)) % N;
		a = (b * pows(a - 1, N - 2)) % N;
		ret = (ret * a) % N;
	}
	cout << ret;
}