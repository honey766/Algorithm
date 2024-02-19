#include <iostream>
using namespace std;
#define F(c) ((c) - 'A')
#define G(n) (cout << (char)(n + 'A'))

struct Node {
	int left;
	int right;
	Node() { left = -1; right = -1; }
};
Node tree[26];

void trav(int n, char c) {
	if (n == -1) return;
	if (c == 0) G(n);
	trav(tree[n].left, c);
	if (c == 1) G(n);
	trav(tree[n].right, c);
	if (c == 2) G(n);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int n;
	char c1, c2, c3;
	cin >> n;
	while (n--) {
		cin >> c1 >> c2 >> c3;
		if (c2 != '.') tree[F(c1)].left = F(c2);
		if (c3 != '.') tree[F(c1)].right = F(c3);
	}
	trav(0, 0);
	cout << '\n';
	trav(0, 1);
	cout << '\n';
	trav(0, 2);
}