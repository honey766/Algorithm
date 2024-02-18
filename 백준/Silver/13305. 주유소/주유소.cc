#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, a, Min = 1'000'000'000;
	long long sum = 0;
	cin >> n;
	int* len = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
		cin >> len[i];
	for (int i = 0; i < n - 1; i++) {
		cin >> a;
		Min = min(Min, a); //지금까지의 가장 싼 가격
		sum += (long long)Min * len[i];
	}
	cin >> a;
	cout << sum;
}