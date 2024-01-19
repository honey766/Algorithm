#include<iostream>
using namespace std;

void inorder(char* tree, int a, int n){
    if(a < n){
    	inorder(tree, 2 * a + 1, n);
    	cout << tree[a];
    	inorder(tree, 2 * a + 2, n);
    }
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test_case;
	int T;
	T = 10;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		cout << '#' << test_case << ' ';
        int n, a; cin >> n;
        char* tree = new char[n];
        for(int i = 0; i < n; i++){
            cin >> a >> tree[i];
            if((i == n / 2 - 1) && (n % 2 == 0)){ //자식 1개
                cin >> a;
            }else if(i <= n / 2 - 1){ //자식 2개
                cin >> a >> a;
            }
        }
        inorder(tree, 0, n);
        cout << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}