#include <iostream>
using namespace std;

int n, base;
int Max[1'048'576]; //수열 저장
int arr[1'048'576]; //지금까지 없앤 Max의 인덱스에 1을 저장, sum세그먼트트리

void initMax() {
	int i;
	for (i = base; i < base + n; i++)
		cin >> Max[i];
	for (; i < 2 * base; i++)
		Max[i] = -1;
	for (i = base - 1; i > 0; i--)
		Max[i] = max(Max[2 * i], Max[2 * i + 1]);
}

void insertSum(int i) {
	i += base;
	arr[i] = 1;
	while (i >>= 1)
		arr[i] = arr[2 * i] + arr[2 * i + 1];
}

int querySum(int l, int r) {
	int sum = 0;
	for (l += base, r += base; l <= r; l >>= 1, r >>= 1) {
		if (l % 2 == 1) sum += arr[l++];
		if (r % 2 == 0) sum += arr[r--];
	}
	return sum;
}

void insertMax(int i) {
	i += base;
	Max[i] = -1;
	while (i >>= 1)
		Max[i] = max(Max[2 * i], Max[2 * i + 1]);
}

//가장 큰 원소의 idx를 반환한다
//같은 원소가 여러개라면 가장 오른쪽 idx를 반환
int queryMax(int i = 1) {
	if (i >= base) return i;
	if (Max[2 * i] <= Max[2 * i + 1])
		return queryMax(2 * i + 1);
	else
		return queryMax(2 * i);
}

/*
1 3 7 6 4 2 5에서 7을 고르고 -1로 채운다. 맨 오른쪽에 가야 하므로 이동 횟수는 (7 - 2 - 1)번 (2는 idx)
해당 자리에는 arr 구간트리에서 1을 넣는다
1 3 -1 6 4 2 5에서 6을 고르고 -1로 채운다. 6의 왼쪽 구간에서 arr구간합은 1이다. 실제 수열에서 6,4,2,5는 1씩 왼쪽으로 갔어야 한다는 뜻이다
6의 실질적 idx은 2, 7을 제외한 맨 오른쪽에 가야 하므로 이동 횟수는 (6 - 2 - 1)번
1 3 -1 -1 4 2 5 : (5-4-1)번
1 3 -1 -1 4 2 -1 : (4-2-1)번
1 3 -1 -1 -1 2 -1 : (3-1-1)번
1 -1 -1 -1 -1 2 -1 : (2-1-1)번
끝
*/

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int idx;
	long long sum = 0;
	cin >> n;
	base = 1;
	while (base < n) base <<= 1;
	initMax();
	for (int i = 0; i < n - 1; i++) {
		idx = queryMax() - base;
		insertMax(idx); //해당 최댓값을 없앤다(-1로 변경)
		insertSum(idx); //해당 idx에 방문했다는 표시로 1을 넣는다
		idx -= querySum(0, idx - 1);
		sum += (n - i) - idx - 1;
	}
	cout << sum;
}