#include <iostream>
#include <stack>
using namespace std;

int Rank(char c) {
	if (c == '*' || c == '/') return 2;
	if (c == '(') return 3;
	if (c == ')') return 0;
	return 1;
}

//a가 b보다 우선순위 같거나 높은 경우
bool f(char a, char b) {
	if (a == '(') return false;
	return Rank(a) >= Rank(b);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	string s;
	stack<char> stk;
	cin >> s;
	for (char c : s) {
		if ('A' <= c && c <= 'Z') {
			cout << c; continue;
		}
		while (!stk.empty() && f(stk.top(), c)) {
			cout << stk.top(); stk.pop();
		}
		if (c == ')') stk.pop(); // '('를 꺼냄
		else stk.push(c);
	}
	while (!stk.empty()) {
		cout << stk.top(); stk.pop();
	}
}