#include <iostream>
#include <stack>
using namespace std;

stack<pair<int, int>> stk;
int ans[1'000'000];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, a, j;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		//스택 안에는 무조건 내림차순으로 원소가 정렬되어 있다.
		//원래 원소보다 더 큰 원소가 들어오면, 원래 원소는 pop된다
		while (!stk.empty() && stk.top().first < a) {
			ans[stk.top().second] = a;
			stk.pop();
		}
		stk.push({ a, i });
	}
	for (int i = 0; i < n; i++) {
		if (!ans[i]) cout << "-1 ";
		else cout << ans[i] << ' ';
	}
}