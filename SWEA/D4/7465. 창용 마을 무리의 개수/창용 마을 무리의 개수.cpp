#include<iostream>
#include<vector>
#include<set>
using namespace std;

int parent[101];

int Find(int x){
    if(x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b){
    int A = Find(a);
    int B = Find(b);
    parent[B] = A;
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cout << '#' << test_case << ' ';
		int n, m, a, b;
        set<int> s;
        cin >> n >> m;
        for(int i = 1; i <= n; i++)
            parent[i] = i;
        while(m--) {
            cin >> a >> b;
            Union(a, b);
        }
		for(int i = 1; i <= n; i++)
            s.insert(Find(i));
        cout << s.size() << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}