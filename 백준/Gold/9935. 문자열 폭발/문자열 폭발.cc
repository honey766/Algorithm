#include <iostream>
#include <stack>
using namespace std;

stack<char> stk;
stack<char> tmp;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	string s, bomb;
	cin >> s >> bomb;
	int n = s.size(), t = bomb.size() - 1;
	for (int i = 0; i < n; i++) {
		stk.push(s[i]);
		while (t >= 0 && !stk.empty() && stk.top() == bomb[t]) {
			tmp.push(stk.top());
			stk.pop();
			t--;
		}
		if (t >= 0) { //폭발 실패
			while (!tmp.empty()) {
				stk.push(tmp.top());
				tmp.pop();
			}
		}
		else { //폭발 성공
			tmp = stack<char>();
		}
		t = bomb.size() - 1;
	}

	if (stk.empty())
		cout << "FRULA";
	else {
		while (!stk.empty()) {
			tmp.push(stk.top());
			stk.pop();
		}
		while (!tmp.empty()) {
			cout << tmp.top();
			tmp.pop();
		}
	}
}