#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MIN(x, y) ((x) > (y) ? (y) : (x))

struct ABP {
	int a;
	int b;
	int p;
};

bool comp(ABP x, ABP y) {
	return x.a < y.a;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int totalSum, n; cin >> n;
	ABP* abp = new ABP[n];
	vector<vector<int>> vec;
	bool* check = new bool[n]();
	int* dp1 = new int[n], * dp2 = new int[n];
	for (int i = 0; i < n; i++)
		cin >> abp[i].a >> abp[i].b >> abp[i].p;
	sort(abp, abp + n, comp); //AB[i].a가 1,2,...,n으로 정렬
	for (int i = 0; i < n; i++) {
		if (check[i]) continue;
		int t = abp[i].b;
		vector<int> tmp;
		tmp.push_back(abp[i].p);
		while (t - 1 != i) {
			tmp.push_back(abp[t - 1].p);
			check[t - 1] = true;
			t = abp[t - 1].b;
		}
		vec.push_back(tmp);
	}//순열 사이클 분할 완료

	//dp1[i]:1과 i+1를 포함하여 최솟값
	//dp2[i]:1은 포함x, 2와 i+1를 포함하여 최솟값
	totalSum = 0;
	for (vector<int> v : vec) {
		if (v.size() == 1) {
			totalSum += v[0]; continue;
		}
		int len = v.size();
		dp1[0] = v[0]; dp1[1] = v[0] + v[1];
		dp2[0] = 10000; dp2[1] = v[1];
		for (int i = 2; i < len; i++) {
			dp1[i] = MIN(dp1[i - 1], dp1[i - 2]) + v[i];
			dp2[i] = MIN(dp2[i - 1], dp2[i - 2]) + v[i];
		}
		totalSum += MIN(MIN(dp1[len - 1], dp1[len - 2]), dp2[len - 1]);
	}
	cout << totalSum;
}