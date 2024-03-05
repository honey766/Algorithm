#include <iostream>
using namespace std;

// (a^b) % n
int pows(long long a, int b, int n) {
	long long ret = 1;
	while (b) {
		if (b % 2) ret = (ret * a) % n;
		a = (a * a) % n;
		b /= 2;
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int a, b, c, k, l, ans1, ans2;
	cin >> a >> b >> c >> k >> l;

	// A^(B^C)  (mod 7)
	// A^(6*x) = 1 (mod 7)
	// (B^C) % 6 = y, A^y (mod 7)을 구한다
	ans1 = pows(b, c, 6);
	ans1 = pows(a, ans1, 7);
	ans1 = (ans1 + k) % 7;

	// (B^C)/A  (mod 7)
	// 페르마의 소정리(곱셈 역원) 이용
	ans2 = (pows(b, c, 7) * pows(a, 5, 7)) % 7;
	ans2 = (ans2 + k) % 7;
	
	ans1 = (int)(ans1 == l);
	ans2 = (int)(ans2 == l);
	cout << ((ans2 << 1) + ans1);
}