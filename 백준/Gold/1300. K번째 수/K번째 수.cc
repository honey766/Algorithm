#include <iostream>
using namespace std;

int n, k;

bool f(int mid) {
	long long cnt = 0;
	//i번째 행에서 mid보다 작거나 같은 수의 개수는 (mid / i)이다
	for (int i = 1; i <= n && cnt < k; i++) {
		cnt += min(mid / i, n);
	}
	return cnt >= k;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> k;
	int mid, l = 0, r = min((long long)1'000'000'000, (long long)n * n);
	while (l < r) {
		mid = (r + l) / 2;
		//mid보다 작거나 같은 수의 개수가, k보다 크거나 같으면, 왼쪽을 본다
		if (f(mid)) r = mid;
		else l = mid + 1;
	}
	cout << r;
}