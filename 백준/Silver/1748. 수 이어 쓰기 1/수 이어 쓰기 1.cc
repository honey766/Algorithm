#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int n, a, digit = 1, digitN = 0;
	long long rst = 0;
	cin >> n;
	while(a = n / digit){
		digitN++;
		if(a >= 10)
			rst += digitN * digit * 9;
		else
			rst += digitN * (n - digit + 1);
		digit *= 10;
	}
	cout << rst;
}