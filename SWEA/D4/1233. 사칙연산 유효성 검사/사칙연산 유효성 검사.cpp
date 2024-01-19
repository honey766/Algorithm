#include<iostream>
using namespace std;

bool isNumeric(char c){
    return '0' <= c && c <= '9';
}

bool valid(char* tree, int a, int n){
    if(a < n / 2)
    	return valid(tree, 2 * a + 1, n) && valid(tree, 2 * a + 2, n) && !isNumeric(tree[a]);
    else if(a < n)
        return isNumeric(tree[a]);
    return false;
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
        if(n % 2 == 0) cout << '0';
        else if(valid(tree, 0, n)) cout << '1';
        else cout << '0';
        cout << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}