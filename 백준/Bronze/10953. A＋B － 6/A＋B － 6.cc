#include <iostream>
using namespace std;
int main(){
	int n;
	string s;
	cin >> n;
	while(n--){
		cin >> s;
		cout << s[0] + s[2] - ('0' * 2) << '\n';
	}
}