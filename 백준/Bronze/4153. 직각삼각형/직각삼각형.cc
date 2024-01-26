#include <iostream>
using namespace std;

int main(){
	int a, b, c;
	while(true){
		cin >> a >> b >> c;
		if(a == 0 && b == 0 && c == 0) break;
		int Max = max(max(a, b), c);
		if(a*a + b*b + c*c == 2 * Max * Max)
			cout << "right\n";
		else
			cout << "wrong\n";
	}
}