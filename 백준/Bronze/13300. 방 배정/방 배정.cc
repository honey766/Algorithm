#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n, k, gen, gra, sum = 0;
	int arr[6][2] = { 0, };
	cin >> n >> k;
	while (n--) {
		cin >> gen >> gra;
		arr[gra - 1][gen]++;
	}
	for (int i = 0; i < 12; i++)
		sum += (arr[i / 2][i % 2] + k - 1) / k;
	cout << sum;
}