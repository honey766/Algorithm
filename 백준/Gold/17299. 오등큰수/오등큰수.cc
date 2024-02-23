#include <iostream>
using namespace std;

int stk[1'000'000];
int ans[1'000'000];
int cnt[1'000'001];
int top;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, a, j;
	cin >> n;
	top = -1;
	for (int i = 0; i < n; i++) {
		cin >> ans[i];
		cnt[ans[i]]++;
	}
	for (int i = 0; i < n; i++) {
		//스택 안에는 무조건 내림차순으로 원소가 정렬되어 있다.
		//원래 원소보다 더 큰 원소가 들어오면, 원래 원소는 pop된다
		while (top >= 0 && cnt[ans[stk[top]]] < cnt[ans[i]]) {
			ans[stk[top]] = ans[i];
			--top;
		}
		stk[++top] = i;
	}
	while (top >= 0)
		ans[stk[top--]] = -1;
	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';
}