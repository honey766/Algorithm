#include <iostream>
using namespace std;

int Max = -1000000000, Min = 1000000000, n;
int* arr;

void cal(int cnt, int curNum, int plus, int minus, int mul, int div) {
	if (cnt == n) {
		Max = curNum > Max ? curNum : Max;
		Min = curNum < Min ? curNum : Min;
		return;
	}
	if (plus)
		cal(cnt + 1, curNum + arr[cnt], plus - 1, minus, mul, div);
	if (minus)
		cal(cnt + 1, curNum - arr[cnt], plus, minus - 1, mul, div);
	if (mul)
		cal(cnt + 1, curNum * arr[cnt], plus, minus, mul - 1, div);
	if (div)
		cal(cnt + 1, curNum / arr[cnt], plus, minus, mul, div - 1);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int a, exp[4];
	cin >> n;
	arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a; arr[i] = a;
	}
	for (int i = 0; i < 4; i++) {
		cin >> a; exp[i] = a;
	}
	cal(1, arr[0], exp[0], exp[1], exp[2], exp[3]);
	cout << Max << '\n' << Min;
}