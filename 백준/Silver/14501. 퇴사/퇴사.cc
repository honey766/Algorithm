#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int n, a; 
	cin >> n;
	vector<int> T(n), P(n), dp(n+1, 0);
	for(int i = 0; i < n; i++)
		cin >> T[i] >> P[i];

	for(int i = 0; i <= n; i++){
		if(i > 0)
			dp[i] = max(dp[i], dp[i-1]);
		if((a = i + T[i]) <= n)
			dp[a] = max(dp[a], dp[i] + P[i]);
	}
	cout << dp[n];
}