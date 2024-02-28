#include <iostream>
#include <deque>
#include <cmath>
using namespace std;

int* in;
int* post;
int* index;
struct Node {
	int num;
	int left;
	int right;
	Node() { left = right = -1; }
};
Node* tree;
int cnt;

//inorder에서 크게 보면 3덩어리이다. (left sub)(root)(right sub)
//이 때 post는 (left)(right)(root)이므로 맨 오른쪽이 루트 노드이다.
//root 번호를 알아냈으므로 left와 right의 크기를 알 수 있다.
//그러면 post에서 left와 right를 분리할 수 있다.
//재귀적으로는 subtree의 루트 노드 번호를 받아온다.
int recur(int root, int l, int r, int rightCnt) {
	if (r < l) return -1;
	if (l == r) return in[r + rightCnt];

	int rootNum = post[r];
	//in과 post는 root에 의해 right subtree의 첫 번째 원소 idx가 다르다. 그 차이를 보정한다
	//left tree와 right tree를 나누는 l과 r은 post 기준으로 한다
	int rootIdx = index[rootNum] - rightCnt;
	
	int left = ++cnt;
	int leftNode = recur(left, l, rootIdx - 1, rightCnt);
	if (leftNode != -1) {
		tree[root].left = left;
		tree[left].num = leftNode;
	}
	else --cnt;

	int right = ++cnt;
	int rightNode = recur(right, rootIdx, r - 1, rightCnt + 1);
	if (rightNode != -1) {
		tree[root].right = right;
		tree[right].num = rightNode;
	}
	else --cnt;

	return rootNum;
}

void pre(int root) {
	if (root == -1) return;
	cout << tree[root].num << ' ';
	pre(tree[root].left);
	pre(tree[root].right);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n;
	cin >> n;
	in = new int[n];
	post = new int[n];
	index = new int[n + 1];
	tree = new Node[n];

	for (int i = 0; i < n; i++) {
		cin >> in[i];
		index[in[i]] = i;
	}
	for (int i = 0; i < n; i++) cin >> post[i];
	tree[0].num = recur(0, 0, n - 1, 0);
	pre(0);
}