#include <iostream>
using namespace std;
#define MAX(x, y) ((x) > (y) ? (x) : (y))

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, count, i, j, max;
	cin >> n;
	int* arr = new int[n];
	int* begin = new int[n], * end = new int[n];
	for (i = 0; i < n; i++) cin >> arr[i];
	//begin[i]: i에서 시작하는 최대, end[i]: i에서 끝나는 최대
	//i에서 무조건 바꿈 (켜짐 <-> 꺼짐)
	//i에서 바꾸며, i를 포함하는 교대 패턴의 최댓값은 begin[i] + end[i] - 1
	//i에서 바꿨으나 i를 포함하지 않을 때 최댓값이 일어난다면, 이는 기계를 0번 바꿨을 때 계산됨
	begin[n - 1] = end[0] = 1;

	for (i = n - 2; i >= 0; i--) {
		if (arr[i] == arr[i + 1]) {
			//i + 1번째를 바꾸지 않음
			j = i;
			while (++j < n - 1 && arr[j] != arr[j + 1]);
			begin[i] = j - i + 1;
		}
		else begin[i] = begin[i + 1] + 1; //i + 1번째를 바꿈

		int k = n - 1 - i; //end는 1부터 시작
		if (arr[k] == arr[k - 1]) {
			j = k;
			while (--j > 0 && arr[j] != arr[j - 1]);
			end[k] = k - j + 1;
		}
		else end[k] = end[k - 1] + 1;
	}
	//기계를 바꾸지 않았을 때 최댓값
	max = 1;
	for (i = 0; i < n - 1; i++)
		if (arr[i] != arr[i + 1])
			max++;
		else
			max = 1;

	for (i = 0; i < n; i++)
		max = MAX(max, begin[i] + end[i] - 1);
	cout << max;
}