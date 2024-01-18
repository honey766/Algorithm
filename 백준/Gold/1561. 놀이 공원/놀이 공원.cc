#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	//minute은 0부터 시작
	long long int n, m, i;
	long long int begin, end, mid, count;
	cin >> n >> m;
	int* arr = new int[m];
	for (i = 0; i < m; i++) cin >> arr[i];

	begin = 0; end = 30 * n; //놀이기구 1개에 30분짜리일 경우보다 약간 높음
	while (begin != end) {
		mid = (begin + end) / 2;
		count = 0;
		for (i = 0; i < m; i++) count += mid / arr[i] + 1; //count: mid분까지 몇 명 태울 수 있나
		if (count < n) begin = mid + 1;
		else end = mid;
	}

	count = 0; begin--;
	for (i = 0; i < m; i++) count += begin / arr[i] + 1;
	if (begin < 0) count = 0;
	begin++;
	for (i = 0; i < m && count < n; i++)
		if (begin % arr[i] == 0)
			count++;
	cout << i;
}