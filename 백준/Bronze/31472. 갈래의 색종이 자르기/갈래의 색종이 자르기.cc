#include <iostream>
using namespace std;

int main(){
	int w, s;
	cin >> w;
	for(s = 2; s * s != 2 * w; s += 2);
	cout << 4 * s;
}