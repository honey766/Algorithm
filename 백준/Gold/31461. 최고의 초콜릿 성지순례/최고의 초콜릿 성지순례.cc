#include <iostream>
using namespace std;

short s[200'000][2];
int a, b, c, d;

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

// i열의 두 개 중 큰 값
int Max(int i){
	return max(s[i][0], s[i][1]);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int tc, n, maxVl, maxVr, sum;
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int j = 0; j < 2; j++)
			for (int i = 0; i < n; i++)
				cin >> s[i][j];
		cin >> a >> b >> c >> d;
		a--; b--; c--; d--;
		if (a > c) {
			swap(a, c); swap(b, d);
		} //a <= c 로 맞춤

		//a의 왼쪽의 최댓값(a열 포함)
		maxVl = s[a][0] + s[a][1];
		sum = 0;
		for (int i = a; i > 0; i--) {
			sum += s[i][0] + s[i][1];
			maxVl = max(maxVl, sum + max(Max(i - 1), s[i - 1][0] + s[i - 1][1]));
		}
		//c의 오른쪽의 최댓값(c열 포함)
		maxVr = s[c][0] + s[c][1];
		sum = 0;
		for (int i = c; i < n - 1; i++) {
			sum += s[i][0] + s[i][1];
			maxVr = max(maxVr, sum + max(Max(i + 1), s[i + 1][0] + s[i + 1][1]));
		}

		if (a < c) { //모든 곳을 돌아다닐 수 있음
			//a+1 ~ c-1 사이의 최댓값
			sum = 0;
			//i열의 둘 중 하나만 방문하거나, 둘 다 방문하거나
			for (int i = a + 1; i < c; i++) {
				sum += max(Max(i), s[i][0] + s[i][1]);
			}
			//a열과 c열에서 왼/오른쪽 고르지 말고 하나만 고르는 게 이득일 수 있음
			//a==c일 때는 이 경우를 포함하면 안 되므로 따로 뺌
			maxVl = max(maxVl, (int)s[a][b]);
			maxVr = max(maxVr, (int)s[c][d]);
			cout << maxVl + maxVr + sum << '\n';
		}
		else { // a == c, 오 or 왼만 갈 수 있음
			cout << max(maxVl, maxVr) << '\n';
		}
	}
}