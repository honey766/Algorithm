#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, i, Max = 0, MaxIdx = 0;
    cin >> n;
    int* arr = new int[n];
    int* dp = new int[n]();
    int* pi = new int[n];
    for (i = 0; i < n; i++) {
        cin >> arr[i];
        pi[i] = -1;
    }
    
    for (i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) 
            if (arr[j] < arr[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                pi[i] = j;
            }
        if (Max < dp[i]) {
            Max = dp[i];
            MaxIdx = i;
        }
    }
    
    i = 0;
    cout << Max + 1 << '\n';
    while (MaxIdx != -1) {
        dp[i++] = arr[MaxIdx];
        MaxIdx = pi[MaxIdx];
    }
    while (--i >= 0)
        cout << dp[i] << ' ';
}