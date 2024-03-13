#include <iostream>
using namespace std;

struct Node {
	int num;
	int left, right;
	Node() { left = right = 1; }
};
int arr[10000];
Node* tree;
int n, cnt;

//target보다 큰 원소 중 가장 왼쪽
// (l ~ r-1) 사이의 원소를 탐색
int lowerbound(int l, int r, int target) {
	int mid;
	while (l < r) {
		mid = (l + r) / 2;
		if (target < arr[mid])
			r = mid;
		else
			l = mid + 1;
	}
	return r;
}

// tree[l]이 루트인 서브트리에서, l이 루트이며, l보다 큰 원소부터 오른쪽 서브트리이다
int f(int l, int r) {
	if (r < l) return -1;
	int rootIdx = cnt;
	tree[cnt++].num = arr[l];
	int idx = lowerbound(l + 1, r + 1, arr[l]); //오른쪽 서브트리의 첫 원소 인덱스(arr)
	tree[rootIdx].left = f(l + 1, idx - 1);
	tree[rootIdx].right = f(idx, r); 
	return rootIdx;
}

void post(int r) {
	if (r == -1) return;
	post(tree[r].left);
	post(tree[r].right);
	cout << tree[r].num << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int a;
	while (cin >> a)
		arr[n++] = a;
	tree = new Node[n];
	f(0, n - 1);
	post(0);
}