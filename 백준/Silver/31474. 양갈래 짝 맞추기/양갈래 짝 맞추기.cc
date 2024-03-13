#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n;
	long long ans = 1;
	for (int i = 3; i < n; i += 2)
		ans *= i;
	cout << ans;
}