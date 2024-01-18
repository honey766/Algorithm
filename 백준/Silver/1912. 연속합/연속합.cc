#include <iostream>
using namespace std;
#define MAX(x,y) (x) > (y) ? (x) : (y)

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, sum, max;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	max = arr[0];
	sum = (arr[0] > 0) ? arr[0] : 0;
	for (int i = 1; i < n; i++) {
		sum += arr[i];
		max = MAX(max, sum);
		if (sum < 0) sum = 0;
	}
	cout << max;
}