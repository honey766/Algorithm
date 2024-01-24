#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Trie {
    static constexpr int max = 26;
    static constexpr char OFFSET = 'a';
    struct TrieNode {
        int child[26];
        bool is_terminal;
        TrieNode() {
            memset(child, -1, max * sizeof(int));
            is_terminal = false;
        }
    };
    std::vector<TrieNode> nodes;

    void findk(int k, int& n, int node_id, std::string& str) {
        if (nodes[node_id].is_terminal) {
            n++;
            if (n == k) return;
        }
        for (int i = 0; i < max; i++) {
            if (nodes[node_id].child[i] != -1) {
                str.push_back(OFFSET + i);
                findk(k, n, nodes[node_id].child[i], str);
                if (n == k) return;
                str.pop_back();
            }
        }
    }

public:
    Trie() {
        nodes.resize(1);
        nodes[0] = TrieNode();
    }
    void insert(const std::string& str) {
        int node_id = 0;
        for (const char c : str) {
            if (nodes[node_id].child[c - OFFSET] == -1) {
                nodes[node_id].child[c - OFFSET] = nodes.size();
                nodes.emplace_back();
            }
            node_id = nodes[node_id].child[c - OFFSET];
        }
        nodes[node_id].is_terminal = true;
    }
    void remove(const std::string str) {
        int node_id = 0;
        for (const char c : str) {
            if (nodes[node_id].child[c - OFFSET] == -1)
                return;
            node_id = nodes[node_id].child[c - OFFSET];
        }
        nodes[node_id].is_terminal = false;
    }
    bool find(const std::string str) {
        int node_id = 0;
        for (const char c : str) {
            if (nodes[node_id].child[c - OFFSET] == -1)
                return false;
            node_id = nodes[node_id].child[c - OFFSET];
        }
        return nodes[node_id].is_terminal;
    }
    string findk(int k) {
        std::string str = "";
        int n = 0;
        findk(k, n, 0, str);
        return str;
    }
};


int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int test_case;
    int T;
    int k;
    std::string s;

    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cout << '#' << test_case << ' ';
        cin >> k >> s;
        if (k > s.size()) {
            cout << "none\n";
            continue;
        }
        std::string tmpS = "";
        Trie trie;
        for (int i = s.size() - 1; i >= 0; i--) {
            tmpS.insert(0, 1, s[i]);
            trie.insert(tmpS);
        }

        s = trie.findk(k);
        cout << s << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}