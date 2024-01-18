#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n;
	int *arr = new int[1000000];
	arr[0] = 1; arr[1] = 2;
	for (int i = 2; i < 1000000; i++)
		arr[i] = (arr[i - 1] + arr[i - 2]) % 15746;
	cin >> n;
	cout << arr[n - 1];
}