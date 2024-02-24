#include <iostream>
using namespace std;
#define ll long long
#define pr pair<ll, pair<ll, ll>>
//https://seastar105.tistory.com/64

ll n, a;
pr xGCD(ll a, ll b) {
	if (b == 0) return { a, {1, 0} };

	pr ret = xGCD(b, a % b);
	ll x = ret.second.first;
	ll y = ret.second.second;
	return { ret.first, {y, x - (a / b) * y} };
}

long long f() {
	pr ret = xGCD(a, n); //ab - m*q = 1
	//베주 항등식에 따르면 a, m의 최대공약수는 1이어야 한다
	if (ret.first != 1) return -1;
	ll t = ret.second.first % n;
	return (t + n) % n;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> a;
	cout << n - a << ' ' << f();
}