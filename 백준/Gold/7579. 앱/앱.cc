#include <iostream>
using namespace std;

int m[100];
short c[100];
int dp[10001]; //dp[i][j] : i번째 물품까지 봤을 때, j의 가치를 만드는 바이트의 최댓값
			   //공간을 줄이기 위해 dp[j]로 바꿈
			   //M이 매우 크므로, 바이트와 가치를 바꿔서 접근

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N, M, C = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> m[i];
	for (int i = 0; i < N; i++) {
		cin >> c[i];
		C += c[i];
	}
	for (int i = 0; i < N; i++)
		for (int j = C; j >= c[i]; j--)
			dp[j] = max(dp[j], dp[j - c[i]] + m[i]);
	for (int i = 0; i <= C; i++)
		if (dp[i] >= M) {
			cout << i;
			break;
		}
}