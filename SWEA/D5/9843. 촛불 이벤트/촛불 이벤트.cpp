#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cout << '#' << test_case << ' ';
		long long n;
    	cin >> n;
    	int left = 0;
    	int right = 1500000000;
    	long long mid;
    	long long ans;
   	    while (left <= right) {
       		mid = left + (right - left) / 2;
        	if (mid * (mid + 1) / 2 <= n) { //mid단을 배치할 수 있다면
            	left = mid + 1; //오른쪽을 검사
            	ans = mid;
        	}
        	else
            	right = mid - 1;
    	}
        if(ans * (ans + 1) / 2 != n) cout << "-1\n";
    	else cout << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}