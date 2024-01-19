#include<iostream>
#include <vector>
using namespace std;
#define MIN(x, y) ((x) > (y) ? (y) : (x))

struct Node{
	int par;
    int left;
    int right;
    Node(){par = -1; left = -1; right = -1;}
};

int treeSize(Node* tree, int cur){
    if(cur == -1) return 0;
    return treeSize(tree, tree[cur].left) + treeSize(tree, tree[cur].right) + 1;
}

int main(int argc, char** argv)
{
   
	int test_case;
	int T;
	
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cout << '#' << test_case << ' ';
		int V, E, first, second, a, b;
        cin >> V >> E >> first >> second;
        first--; second--;
        Node* tree = new Node[V]();
        while(E--){
            cin >> a >> b;
            a--; b--;
            if(tree[a].left == -1) tree[a].left = b;
            else tree[a].right = b;
            tree[b].par = a;
        }
        
        vector<int> firstVec, secondVec;
        int cur = first;
        while(cur != -1){
            firstVec.push_back(cur);
            cur = tree[cur].par;
        }
        cur = second;
        while(cur != -1){
            secondVec.push_back(cur);
            cur = tree[cur].par;
        }
		
        int fLen = firstVec.size(), sLen = secondVec.size();
        int par, Min = MIN(fLen, sLen);
        int i = 0;
		while(++i <= Min && firstVec[fLen - i] == secondVec[sLen - i])
        	par = firstVec[fLen - i];
        cout << par + 1 << ' ' << treeSize(tree, par) << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}