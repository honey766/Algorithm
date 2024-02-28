#include <iostream>
#include <vector>
#include <cstring>
#include <set>
using namespace std;



class Trie {
	struct TrieNode {
		int child[26];
		bool is_terminal;
		set<char> who; //26개 문자 중 어떤 게 들어왔는지
		TrieNode() { 
			memset(child, -1, 104);
			is_terminal = false; 
		}
	};
	vector<TrieNode> nodes;
	int totCnt;

public:
	Trie() : nodes(1) {}
	void init() {
		nodes.resize(1);
		nodes[0] = TrieNode();
	}
	void insert(string& s) {
		int node_id = 0;
		for (char c : s) {
			if (nodes[node_id].child[c - 'a'] == -1) {
				nodes[node_id].child[c - 'a'] = nodes.size();
				nodes[node_id].who.insert(c - 'a');
				nodes.emplace_back();
			}
			node_id = nodes[node_id].child[c - 'a'];
		}
		nodes[node_id].is_terminal = true;
	}
	void trav(int id, int cnt) {
		set<char>& st = nodes[id].who;
		if (st.size() == 1 && !nodes[id].is_terminal) {
			trav(nodes[id].child[*st.begin()], cnt);
			return;
		}
		if (nodes[id].is_terminal) {
			totCnt += cnt;
		}
		for (auto it = st.begin(); it != st.end(); it++) {
			trav(nodes[id].child[*it], cnt + 1);
		}
	}
	void trav(int n) {
		totCnt = 0;
		set<char>& st = nodes[0].who;
		for (auto it = st.begin(); it != st.end(); it++) {
			trav(nodes[0].child[*it], 1);
		}
		cout << 1.0 * totCnt / n << '\n';
	}
};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cout << fixed;
	cout.precision(2);
	int n;
	string s;
	Trie tr;
	while (cin >> n) {
		tr.init();
		for(int i = 0; i < n; i++) {
			cin >> s;
			tr.insert(s);
		}
		tr.trav(n);
	}
}