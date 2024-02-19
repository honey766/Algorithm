#include <iostream>
#include <set>
using namespace std;
#define POW(x) ((x) * (x))

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int n, Min = 5;
	set<int> sum1, sum2; //숫자 1개, 숫자 2개로 만들 수 있는 숫자
	cin >> n;

	for (int i = 1; i <= 223; i++) {
		sum1.insert(POW(i));
		if (POW(i) == n) {
			cout << 1;
			return 0;
		}
		for (int j = i; j <= 223; j++) {
			if (POW(i) + POW(j) == n)
				Min = 2;
		}
	}
	if (Min == 2) {
		cout << 2;
		return 0;
	}

	for (int i = 0; i < 223; i++)
		for (int j = i; j < 223; j++)
			if (sum1.count(n - POW(i) - POW(j))) {
				cout << 3;
				return 0;
			}
	cout << 4;
}