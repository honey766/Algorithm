#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, a;
	long long int *arr = new long long int[100];
	arr[0] = 1; arr[1] = 1; arr[2] = 1;
	for (int i = 3; i < 100; i++)
		arr[i] = arr[i - 2] + arr[i - 3];
	cin >> n;
	while (n--) {
		cin >> a;
		cout << arr[a - 1] << '\n';
	}
}