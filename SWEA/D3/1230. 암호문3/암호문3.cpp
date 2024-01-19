#include<iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cout << '#' << test_case << ' ';
		vector<int> list;
        list.reserve(10);
		char c; int a, n, x, y;
		string s;
		cin >> n;
		while (n--) {
			cin >> a; list.push_back(a);
		}
		cin >> n;
		while (n--) {
			cin >> c >> x;
			switch (c) {
			case 'I':
				cin >> y;
				for (int i = 0; i < y; i++) {
					cin >> a;
					list.insert(list.begin() + x + i, a);
				}
				break;
			case 'D':
				cin >> y;
				list.erase(list.begin() + x, list.begin() + x + y);
				break;
			case 'A':
				while (x--) {
					cin >> a;
					list.push_back(a);
				}
				break;
			}
		}
		for(int i = 0; i < 10; i++)
			cout << list[i] << ' ';
        cout << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}