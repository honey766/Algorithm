#include <iostream>
using namespace std;
#define MAX(x, y) ((x) > (y) ? (x) : (y))

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, k; cin >> n >> k;
	int* w = new int[n + 1];
	int* v = new int[n + 1];
	int** dp = new int* [n + 1]; 
	//dp[i][j] : 1th~ith의 물품만을 사용해서, 가방 무게 j일 때 가치의 최댓값
	for (int i = 0; i <= n; i++) {
		if(i > 0) cin >> w[i] >> v[i];
		dp[i] = new int[k + 1];
		dp[i][0] = 0;
	}
	for (int i = 1; i <= k; i++) dp[0][i] = 0;
    
    //dp 시작
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j < w[i]) dp[i][j] = 0;
			else dp[i][j] = dp[i - 1][j - w[i]] + v[i];
            //0~(i-1)th 물품으로 가방 무게 j-w[i]만큼 채워야 함
			dp[i][j] = MAX(MAX(dp[i][j], dp[i - 1][j]), dp[i][j - 1]);
			//ith 물품이 안 들어가야 하는 경우에는, 직전 애들의 최댓값 인계
		}
	}
	cout << dp[n][k];
}