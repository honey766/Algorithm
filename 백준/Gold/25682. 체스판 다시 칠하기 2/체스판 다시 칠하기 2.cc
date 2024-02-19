#include <iostream>
using namespace std;

int good[2001][2001]; //i+j가 짝수일 때 B, 홀수일 때 W가 들어감.
					  //(1, 1) ~ (i, j) 사각형 칸에 제대로 들어간 개수

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, m, k, cor, cnt, Min = 10'000'000;
	string s;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		for (int j = 1; j <= m; j++) {
			
			if (((i + j) % 2 == 0 && s[j - 1] == 'B') || ((i + j) % 2 && s[j - 1] == 'W'))
				good[i][j] = 1;
			good[i][j] += good[i - 1][j] + good[i][j - 1] - good[i - 1][j - 1];
		}
	}
	for (int i = 0; i <= n - k; i++) {
		for (int j = 0; j <= m - k; j++) {
			cor = good[i + k][j + k] - good[i][j + k] - good[i + k][j] + good[i][j];
			cnt = k * k - cor; //잘못된 개수
			cnt = (cnt > k * k / 2) ? k * k - cnt : cnt;
			Min = min(Min, cnt);
		}
	}
	cout << Min;
}