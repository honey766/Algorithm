#include <iostream>
using namespace std;
#define DIF(a, b) (abs(a.x - b.x) + abs(a.y - b.y))
#define INF 2'000'000'000

struct Cor {
	short x, y;
};

Cor a[1002];
int dp[1002][1002];
short save[1001][2];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	short n, w;
	int Max, Min, i, j;
	cin >> n >> w;
	string ans;
	ans.resize(w);
	a[0] = { 1, 1 };
	a[1] = { n, n };
	for (i = 2; i < w + 2; i++)
		cin >> a[i].x >> a[i].y;
	for (i = 0; i < w + 2; i++)
		for (j = 0; j < w + 2; j++)
			dp[i][j] = INF;
	dp[0][1] = 0;
	for (i = 0; i < w + 1; i++) {
		for (j = 0; j < w + 1; j++) {
			if (i == j) continue;
			Max = max(i, j) + 1;
			dp[Max][j] = min(dp[Max][j], dp[i][j] + DIF(a[Max], a[i]));
			dp[i][Max] = min(dp[i][Max], dp[i][j] + DIF(a[Max], a[j]));
			if (Max == j + 1 && dp[Max][j] == dp[i][j] + DIF(a[Max], a[i]))
				save[j][1] = i;
			if (i + 1 == Max && dp[i][Max] == dp[i][j] + DIF(a[Max], a[j]))
				save[i][0] = j;
		}
	}
	Min = INF;
	for (int k = 0; k < w + 1; k++) {
		if (Min > dp[k][w + 1]) {
			i = k; j = w + 1;
			Min = dp[k][w + 1];
		}
		if (Min > dp[w + 1][k]) {
			i = w + 1; j = k;
			Min = dp[w + 1][k];
		}
	}
	
	// dp[i][i-3]에서 시작하면, dp[i-2][i-3]까지는 1을 무조건 고른다. 이 정보는 저장하지 않는다
	// dp[i-2][i-3]에서는 1번을 고르고, 다음은 2번을 고른다. 
	// dp[i][j] -> dp[j+1][j] (i<j)로 갔을 텐데, 이 i를 save[j][1]에저장한다
	while (i > 1 || j > 1) {
		if (i > j) {
			ans[i - 2] = '1';
			if (--i == j) i = save[j][1];
		}
		else { // i < j
			ans[j - 2] = '2';
			if (--j == i) j = save[i][0];
		}
	}
	cout << Min << '\n';
	for (i = 0; i < w; i++)
		cout << ans[i] << '\n';
}