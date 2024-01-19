#include<iostream>
#include<string>
using namespace std;

struct Node{
	int num;
    int left;
    int right;
    Node(){left = -1; right = -1;}
};

double cal(Node* tree, int a, int n){
	if(tree[a].num >= 0) return tree[a].num;
    char c = tree[a].num + 256;
    switch(c){
        case '+':
            return cal(tree, tree[a].left, n) + cal(tree, tree[a].right, n);
            break;
        case '-':
            return cal(tree, tree[a].left, n) - cal(tree, tree[a].right, n);
            break;
        case '*':
            return cal(tree, tree[a].left, n) * cal(tree, tree[a].right, n);
            break;
        case '/':
            return cal(tree, tree[a].left, n) / cal(tree, tree[a].right, n);
            break;   
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	T = 10;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
    	cout << '#' << test_case << ' ';
		int a, b, n; cin >> n;
        Node* tree = new Node[n]();
        string s;
        for(int i = 0; i < n; i++){
			getline(cin, s);
            cin >> a >> s;
            if(s[0] < '0' || '9' < s[0]){
                cin >> a >> b;
                tree[i].num = s[0] - 256;
                tree[i].left = a - 1;
                tree[i].right = b - 1;
            }else
                tree[i].num = stoi(s);
        }
        cout << (int)cal(tree, 0, n) << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}