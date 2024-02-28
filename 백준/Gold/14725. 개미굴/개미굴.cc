#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Trie {
	struct TrieNode {
		map<string, int> child;
		bool is_terminal;
		TrieNode() { is_terminal = false; }
	};
	vector<TrieNode> nodes;

public:
	Trie() : nodes(1) {}
	void insert(string* arr) {
		int node_id = 0;
		for (int i = 0; arr[i] != "0"; i++) {
			if (!nodes[node_id].child.count(arr[i])) {
				nodes[node_id].child[arr[i]] = nodes.size();
				nodes.emplace_back();
			}
			node_id = nodes[node_id].child[arr[i]];
		}
		nodes[node_id].is_terminal = true;
	}
	void trav(int node_id, int i) {
		for (auto it = nodes[node_id].child.begin(); it != nodes[node_id].child.end(); it++) {
			for (int j = 0; j < i; j++)
				cout << '-';
			cout << (*it).first << '\n';
			trav((*it).second, i + 2);
		}
	}
};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, k, i;
	string s, arr[16];
	Trie tr;
	cin >> n;
	while (n--) {
		cin >> k;
		for (i = 0; i < k; i++)
			cin >> arr[i];
		arr[i] = "0";
		tr.insert(arr);
	}
	tr.trav(0, 0);
}