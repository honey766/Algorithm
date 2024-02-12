#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int cnt;

class Trie {
    struct TrieNode {
        int child[26];
        bool is_terminal;
        TrieNode() {
            memset(child, -1, 104);
            is_terminal = false;
        }
    };
    vector<TrieNode> nodes;
public:
    Trie() : nodes(1) {}
    void init() {
        nodes.resize(1);
        nodes[0] = TrieNode();
    }
    void insert(const string& str) {
        int node_id = 0;
        for (char c : str) {
            if (nodes[node_id].child[c - 'a'] == -1) {
                nodes[node_id].child[c - 'a'] = nodes.size();
                nodes.emplace_back();
            }
            node_id = nodes[node_id].child[c - 'a'];
            nodes[node_id].is_terminal = true;
        }
    }

    vector<char> vec;
    void f(int n, int node_id) {
        if (nodes[node_id].is_terminal) ++cnt;
        if (cnt == n) return;
        for (int i = 0; i < 26; ++i) {
            if (nodes[node_id].child[i] == -1) continue;
            vec.push_back('a' + i);
            f(n, nodes[node_id].child[i]);
            if (cnt == n) return;
            vec.pop_back();
        }
    }
    vector<char> f(int n) {
        vec.clear();
        f(n, 0);
        return vec;
    }
};

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int test_case;
    int T, n;
    string s;

    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> n >> s;
        Trie Tr;
        cnt = 0;
        for (int i = 0; i < s.size(); ++i)
            Tr.insert(s.substr(i, s.size() - i));
        vector<char> vec = Tr.f(n);
        cout << '#' << test_case << ' ';
        if (cnt < n) cout << "none";
        else
            for (char c : vec)
                cout << c;
        cout << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}